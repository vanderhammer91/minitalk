/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:13:19 by ivanderw          #+#    #+#             */
/*   Updated: 2023/04/25 21:46:19 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources/libft/libft.h"
#include "includes/minitalk.h"


void	print_byte(int *byte)
{
	int i;

	i = 0;
	while(i < 8)
	{
		ft_putchar(byte[i] + '0');
		i++;
	}
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
	static int				i;
	static pid_t			client_pid = 0;
	int	byte[8];

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
			kill(client_pid = info->si_pid, SIGUSR1);
			kill(client_pid = info->si_pid, SIGUSR2);
			client_pid = 0;
		}
		else
		{
			ft_printf("%c", byte_to_char(byte));
			i = 0;
		}
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;
	time_t t;   // not a primitive datatype
    time(&t);


	//printf("day: %s\n", ft_substr(ctime(&t), 4, 16));
	ft_printf("[SERVER: %s]:", ft_substr(ctime(&t), 4, 12));
 	ft_printf("[PID: %d]\n", getpid());
	s_sigaction.sa_sigaction = sig_handle;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}

