/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:30:07 by ivanderw          #+#    #+#             */
/*   Updated: 2023/04/28 13:35:58 by ivanderw         ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	int			my_pid;
	const char	*yellow_text;

	yellow_text = YELLOW "CLIENT" RESET_COLOUR;
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_printf("[");
		write(STDOUT_FILENO, yellow_text, ft_strlen(yellow_text));
		ft_printf("]: ");
		ft_printf("[ERROR]: Incorrect parameters\n");
		return (1);
	}
	my_pid = ft_atoi(argv[1]);
	send_string(my_pid, argv[2]);
	return (0);
}
