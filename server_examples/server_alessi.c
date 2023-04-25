/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:56:56 by atucci            #+#    #+#             */
/*   Updated: 2023/04/21 20:47:57 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

// Function to handle signal and convert received bits to characters
void	handle_signal(int signal_number, siginfo_t *signal_info, void *unused)
{
	static int	current_char_bits; // Stores the bits of the current character 
	//being received
	static int	current_bit_index; // Stores the index of the bit currently 
	//being received

	(void)unused; // Unused parameter

	// If the signal received is SIGUSR1, set the corresponding bit in the 
	// current character bits
	if (signal_number == SIGUSR1)
		current_char_bits += 1 << current_bit_index; // 1 << current_bit_index 
	//is equivalent to 2^current_bit_index

	current_bit_index++; // Move to the next bit

	// If all 8 bits of the current character have been received, print the 
	// character and reset the bit counters
	if (current_bit_index == 8)
	{
		write(1, &current_char_bits, 1); // Write the character represented by 
		//the bits to the console
		if (current_char_bits == '\0') // If the null character is received, 
			//send SIGUSR1 to indicate end of message
			kill(signal_info->si_pid, SIGUSR1);
		current_char_bits = 0; // Reset the bit counter
		current_bit_index = 0; // Reset the bit index
	}
}

int	main(void)
{
	pid_t				process_id;
	struct sigaction	signal_action;

	process_id = getpid();
	ft_printf("PID is: %d\n", process_id);

	// Set up signal handler for SIGUSR1 and SIGUSR2
	signal_action.sa_sigaction = &handle_signal;
	signal_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal_action, NULL);
	sigaction(SIGUSR2, &signal_action, NULL);
	sigemptyset(&signal_action.sa_mask);

	// Wait indefinitely for signals
	while (1)
		pause();
}

