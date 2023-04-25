/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:30:07 by ivanderw          #+#    #+#             */
/*   Updated: 2023/04/25 21:47:03 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/minitalk.h"
#include "sources/libft/libft.h"

/*
int	g_bit_control;

void	send_char(char c, pid_t pid)
{
	int	bit;

	bit = __CHAR_BIT__ * sizeof(c) - 1;
	while (bit >= 0)
	{
		if (kill(pid, 0) < 0)
		{
			ft_printf("ERROR : cant send sig to pid : %d\n", pid);
			exit(EXIT_FAILURE);
		}
		g_bit_control = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (g_bit_control != 1)
			usleep(10);
	}
}

void	send_str(char *str, pid_t pid)
{
	int	cur;

	cur = 0;
	while (str[cur])
	{
		send_char(str[cur], pid);
		cur++;
	}
	send_char(0, pid);
}

void	sig_usr(int sig)
{
	if (sig == SIGUSR1)
		g_bit_control = 1;
	else if (sig == SIGUSR2)
	{
		ft_printf("Message received !\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Usage : ./client <pid> <string to send>\n");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, &sig_usr);
	signal(SIGUSR2, &sig_usr);
	pid = ft_atoi(argv[1]);
	if (!pid)
	{
		ft_printf("%s is an invalid pid\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	send_str(argv[2], pid);
	while (1)
		sleep(1);
}
*/
/*
// This function sends a single bit (either 0 or 1) to the server
void	send_bit(int server_pid, int q)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (q & (1 << bit))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}
// This function sends a message to the server by converting 
// each character into a serives of bits
void	send_message(pid_t pid, char *message)
{
	int	count;
   
	count = 0;
	while (message[count] != '\0')
	{
		send_bit(pid, message[count]);
		usleep(100);
		count++;
	}
}
void	receipt(int f)
{
	(void)f;
	ft_printf("test!\n");
	ft_printf("\033[32m%s\033[0m\n", "message receipt\n");
}

int	main(int ac, char *av[])
{
	int		server_pid;	// this is the process ID of the process 
	char	*message;
	
	if (ac != 3)
	{
		// write something here
		ft_printf("\033[31mthe fuck are you doing bro?\n Check yourself!\033[31m\n");
		return (1);
	}

	server_pid = ft_atoi(av[1]); // ascii to int for the first message (?)
	message = av[2]; //  assign the second string to the previously  declared message
	send_message(server_pid, message); // calling the function send  message
	signal(SIGUSR1, receipt); // print  the receipt 
	send_bit(server_pid, '\n');
	send_bit(server_pid, '\0');

	return(0);
}
*/
/*
static int	send_bin(pid_t pid, char c)
{
	int			bit;

	bit = 7;
	while (--bit > -1)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
	}
	return (0);
}

static int	ftp_server(pid_t pid_num, char *str)
{
	int	i;

	i = 0;
	while (str[i] >= ' ' && str[i] <= '~')
	{
		if (send_bin(pid_num, str[i]))
			return (1);
		++i;
	}
	i = 0;
	while (i < 7)
	{
		kill(pid_num, SIGUSR1);
		i++;
		usleep(1000);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid_num;

	write(1, GREEN "Code > ", 14);
	fflush(stdout);
	system("ps | grep \"./server\" | awk 'NR==3 { print $1 }'");
	if (argc < 3)
	{
		write(STDOUT_FILENO, "Introduce un PID y una cadena\n", 31);
		return (1);
	}
	else if (argc == 3)
	{
		pid_num = ft_atoi(argv[1]);
		if (pid_num == 0)
			return (1);
		if (pid_num)
			ftp_server(pid_num, argv[2]);
	}
	return (0);
}
*/
/*
static void	feedback(int sig)
{
	(void)sig;
	ft_printf("\033[32m%s\033[0m\n", "<< message received! >>\n");
	//static int	received = 0;
	
	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putnbr(received);
		ft_putchar('\n');
		exit(0);
	}
	
}
*/
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

int	main(int argc, char **argv)
{
	time_t t;   // not a primitive datatype
    time(&t);

	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_printf("[CLIENT: %s]:", ft_substr(ctime(&t), 4, 12));
 		ft_printf("[ERROR]: Incorrect parameters\n");
		return (1);
	}
	else
	{
		ft_printf("[CLIENT: %s]:", ft_substr(ctime(&t), 4, 12));
		ft_putstr("Sent    : ");
		ft_putnbr(ft_strlen(argv[2]));
		ft_putchar('\n');
		send_string(ft_atoi(argv[1]), argv[2]);
		//signal(SIGUSR1, feedback);
	}

	while (1)
		pause();
	return (0);
}

