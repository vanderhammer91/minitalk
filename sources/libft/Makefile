# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 12:14:15 by ivanderw          #+#    #+#              #
#    Updated: 2023/04/26 22:13:10 by ivanderw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wextra -Werror -Wall

CC = gcc

NAME = libft.a

source = 	ft_putchar.c						\
			ft_putstr.c							\
			ft_putnbr.c							\
			ft_strlen.c							\
			ft_atoi.c							\
			ft_strdup.c							\
			ft_substr.c							\
			ft_printf_printchar_length.c		\
			ft_printf_printstr_length.c			\
			ft_printf_printdecimal_length.c		\
			ft_printf_printunsigned_length.c	\
			ft_printf_printhex_length.c			\
			ft_printf_printadd_length.c			\
			ft_printf.c							\

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
