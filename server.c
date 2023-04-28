/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:13:19 by ivanderw          #+#    #+#             */
/*   Updated: 2023/04/28 13:35:32 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources/libft/libft.h"
#include "includes/minitalk.h"

unsigned char	byte_to_char(int arr[])
{
	unsigned char	byte;
	int				i;
	char			c;

	byte = 0;
	i = 0;
	while (i < 8)
	{
		byte |= (arr[i] << (7 - i));
		i++;
	}
	c = (char) byte;
	return (c);
}

static void	sig_handle(int sig, siginfo_t *info, void *context)
{
	static int	i;
	int			byte[8];

	(void) info;
	(void) context;
	if (sig == SIGUSR1)
		byte[i] = 1;
	else if (sig == SIGUSR2)
		byte[i] = 0;
	i++;
	if (i % 8 == 0)
	{
		ft_printf("%c", byte_to_char(byte));
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;
	const char			*server_text;
	const char			*pid_text;
	time_t				t;

	time(&t);
	server_text = GREEN "SERVER" RESET_COLOUR;
	pid_text = GREEN "PID" RESET_COLOUR;
	ft_printf("[");
	write(STDOUT_FILENO, server_text, ft_strlen(server_text));
	ft_printf("]: <");
	write(STDOUT_FILENO, pid_text, ft_strlen(pid_text));
	ft_printf("> = %d", getpid());
	s_sigaction.sa_sigaction = sig_handle;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	sigemptyset(&s_sigaction.sa_mask);
	while (1)
		pause();
}
