# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 16:02:55 by vduriez           #+#    #+#              #
#    Updated: 2021/11/22 00:31:29 by vduriez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

INCLUDE = -Lminilibx -lX11 -lXext -lmlx -lm

SRC =	fdf.c						\
		srcs/get_next_line.c		\
		srcs/get_next_line_utils.c	\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./minilibx
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDE) $(LIB)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
