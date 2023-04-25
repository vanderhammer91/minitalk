# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 12:14:15 by ivanderw          #+#    #+#              #
#    Updated: 2023/04/25 18:57:00 by ivanderw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wextra -Werror -Wall

CC = gcc

NAME = libft.a

source = 	ft_putchar.c							\
			ft_putstr.c								\
			ft_putnbr.c								\
			ft_strlen.c								\
			ft_atoi.c								\
			ft_strdup.c								\
			ft_substr.c								\
			ft_printf_get_printchar_length.c		\
			ft_printf_get_printstr_length.c			\
			ft_printf_get_printdecimal_length.c		\
			ft_printf_get_printunsignedint_length.c	\
			ft_printf_get_printhex_length.c			\
			ft_printf_get_printaddress_length.c		\
			ft_printf.c								\

OBJECTS = $(source:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAG) -o $@ -c $<

$(NAME):	$(OBJECTS)
						ar src $(NAME) $(OBJECTS)
clean:
						rm -f $(OBJECTS)
fclean:		clean
						rm -f $(NAME)
re:			fclean all
