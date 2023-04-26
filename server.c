/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:13:19 by ivanderw          #+#    #+#             */
/*   Updated: 2023/04/26 20:46:39 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources/libft/libft.h"
#include "includes/minitalk.h"

char *get_timestamp(void)
{
	time_t t;      
	time(&t);
	return (ft_substr(ctime(&t), 4, 15));
}

unsigned char byte_to_char(int arr[])
{
	unsigned char byte = 0;
	int				i = 0;
	while (i < 8)
	{
		byte |= (arr[i] << (7 - i));
		i++;
	}
	char c = (char) byte;
	return (c);
}

static void	sig_handle(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	static int	i;
	static int 	start;
	int			byte[8];
	const char* green_text = GREEN_COLOR "SERVER" RESET_COLOR;
	const char* yellow_text = YELLOW_COLOR "CLIENT" RESET_COLOR;
	
	if (start == 0 && (sig == SIGUSR1 || sig == SIGUSR2))
	{
		ft_printf("\n[");	
		write(STDOUT_FILENO, green_text, ft_strlen(green_text));
		ft_printf("][%s]: ", get_timestamp());
	}
		if (sig == SIGUSR1)
		byte[i] = 1;
	else if (sig == SIGUSR2)
		byte[i] = 0;
	i++;	
	if (i % 8 == 0)
	{
		if(byte_to_char(byte) == 255)
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR2);
			start = 0;
			i = 0;
		}
		else
		{
			if (start == 7)
			{
				ft_printf("<");
				write(STDOUT_FILENO, yellow_text, ft_strlen(green_text));
				ft_printf(">: ");
			}
			ft_printf("%c", byte_to_char(byte));
			kill(info->si_pid, SIGUSR1);
		}
		i = 0;
	}
	start++;
}

int	main(void)
{
	struct sigaction	s_sigaction;
	const char* green_text = GREEN_COLOR "SERVER" RESET_COLOR;
	time_t t;	
	time(&t);

	ft_printf("[");
	write(STDOUT_FILENO, green_text, ft_strlen(green_text));
	ft_printf("][%s]: ", get_timestamp());
 	ft_printf("<PID> = %d", getpid());
	s_sigaction.sa_sigaction = sig_handle;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	sigemptyset(&s_sigaction.sa_mask);
	while (1)
		pause();
}

