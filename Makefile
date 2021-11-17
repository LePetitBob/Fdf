# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 16:02:55 by vduriez           #+#    #+#              #
#    Updated: 2021/11/12 18:58:57 by vduriez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

INCLUDE = -lmlx -Lminilibx -lX11 -lXext

SRC =	fdf.c						\
		srcs/get_next_line.c		\
		srcs/get_next_line_utils.c	\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $(NAME) $(OBJ) $(INCLUDE) $(LIB)

$(LIB):
	make -C ./minilibx

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
