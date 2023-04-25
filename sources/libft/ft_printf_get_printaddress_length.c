/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printaddress_length.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:21:10 by ivanderw          #+#    #+#             */
/*   Updated: 2023/04/24 19:33:34 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_address_length(uintptr_t n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		length ++;
		n = n / 16;
	}
	return (length);
}

void	ft_printaddress(uintptr_t n)
{
	if (n >= 16)
	{
		ft_printaddress(n / 16);
		ft_printaddress(n % 16);
	}
	else if (n < 10)
		ft_putchar(n + '0');
	else if (n >= 10 && n < 16)
		ft_putchar(n - 10 + 'a');
}

int	ft_printf_get_printaddress_length(unsigned long long my_ptr)
{
	int	print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (my_ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		ft_printaddress(my_ptr);
		print_length += ft_address_length(my_ptr);
	}
	return (print_length);
}
