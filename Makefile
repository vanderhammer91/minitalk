# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 15:37:29 by ivanderw          #+#    #+#              #
#    Updated: 2023/04/24 19:48:09 by ivanderw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client
NAME2 = server

SRC1 = client.c 
SRC2 = server.c

LIBFT = sources/libft/libft.a
LIBFT_DIR = sources/libft

CC = gcc
FLAGS = -Wextra -Werror -Wall

.PHONY: all bonus clean fclean re

all: $(NAME1) $(NAME2)

OBJECTS = $(source:%.c=%.o)

$(NAME1): $(SRC1) $(LIBFT)
	$(CC) $(FLAGS) -L $(LIBFT_DIR) -lft $(NAME1).c -o $(NAME1)

$(NAME2): $(SRC2) $(LIBFT)
	$(CC) $(FLAGS) -L $(LIBFT_DIR) -lft $(NAME2).c -o $(NAME2)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME1) $(NAME2)
	make -C $(LIBFT_DIR) fclean

re:	fclean all
