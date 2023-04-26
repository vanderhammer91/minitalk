/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:30:07 by ivanderw          #+#    #+#             */
/*   Updated: 2023/04/26 20:44:45 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/minitalk.h"
#include "sources/libft/libft.h"

static void	send_string(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

char *get_timestamp(void)
{
	time_t t;      
	time(&t);
	return (ft_substr(ctime(&t), 4, 15));
}

void	sig_handle(int sig)
{
	static int count;
	const char* yellow_text = YELLOW_COLOR "CLIENT" RESET_COLOR;
	if (sig == SIGUSR1)
		count++;
	else if (sig == SIGUSR2)
	{
		ft_printf("[");
		write(STDOUT_FILENO, yellow_text, ft_strlen(yellow_text));
		ft_printf("][%s]: <SERVER> ",get_timestamp());
		ft_printf("received %d characters successfully. \n", count);
		count = 0;
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	int my_pid;
	const char* yellow_text = YELLOW_COLOR "CLIENT" RESET_COLOR;


	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_printf("[");
		write(STDOUT_FILENO, yellow_text, ft_strlen(yellow_text));
		ft_printf("][%s]: ", get_timestamp());
 		ft_printf("[ERROR]: Incorrect parameters\n");
		return (1);
	}
	signal(SIGUSR1, &sig_handle);
	signal(SIGUSR2, &sig_handle);
	my_pid = ft_atoi(argv[1]);
	ft_printf("[");
	write(STDOUT_FILENO, yellow_text, ft_strlen(yellow_text));
	ft_printf("][%s]: ", get_timestamp());
	ft_putstr("Sent ");
	ft_putnbr(ft_strlen(argv[2]));
	ft_printf(" characters.");
	ft_putchar('\n');
	send_string(my_pid, argv[2]);
	while (1)
		sleep(1);	
}

