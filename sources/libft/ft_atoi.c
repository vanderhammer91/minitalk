/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:01:35 by ivanderw          #+#    #+#             */
/*   Updated: 2023/04/24 18:53:24 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
NAME
     atoi, atoi_l -- convert ASCII string to integer

SYNOPSIS
     #include <stdlib.h>
     int
     atoi(const char *str);

DESCRIPTION
     The atoi() function converts the initial portion of the string pointed 
	 to by str to int representation.
     It is equivalent to:
           (int)strtol(str, (char **)NULL, 10);

FROM STROL:

	The string may begin with an arbitrary amount of white space 
	(as determined by isspace(3)) followed by a single optional `+' or `-' sign.  
	If base is zero or 16, the string may then include a ``0x'' prefix, and
    the number will be read in base 16; otherwise, a zero base is taken as 10 
	(decimal) unless the next character is `0', in which case it is taken as 
	8 (octal).

IMPLEMENTATION NOTES
     The atoi() and atoi_l() functions are thread-safe and async-cancel-safe.
*/
#include "libft.h"
/*
static int	is_sign(int c)
{
	if (c == 43 || c == 45)
		return (1);
	return (0);
}
*/
int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
