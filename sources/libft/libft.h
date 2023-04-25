/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:36:34 by ivanderw          #+#    #+#             */
/*   Updated: 2023/04/25 18:56:32 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
int		ft_strlen(const char *s);
char	*ft_strdup(char *src);
char	*ft_substr(const char *s, unsigned int start, size_t len);

//void	*ft_calloc(size_t count, size_t size);
//char	*ft_itoa(int n);

int		ft_printf_get_printchar_length(char n);

int		ft_printf_get_printstr_length(char *str);

int		ft_printf_get_printdecimal_length(int n);

int		ft_printf_get_printunsignedint_length(unsigned int n);

int		hex_length(unsigned int n);
void	print_hex(unsigned int n, const char mychar);
int		ft_printf_get_printhex_length(unsigned int n, const char mychar);

int		ft_address_length(uintptr_t n);
void	ft_printaddress(uintptr_t n);
int		ft_printf_get_printaddress_length(unsigned long long my_ptr);

int		get_output_length(va_list args, const char mychar);
int		ft_printf(const char *inputstr, ...);
#endif

