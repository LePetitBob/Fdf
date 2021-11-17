# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/25 14:28:44 by vduriez           #+#    #+#              #
#    Updated: 2020/09/03 11:27:51 by vduriez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = ft_atoi.c			\
      ft_isalnum.c		\
      ft_isalpha.c		\
      ft_isascii.c		\
      ft_isdigit.c		\
      ft_strlen.c		\
      ft_strnstr.c		\
      ft_strncmp.c		\
      ft_toupper.c		\
      ft_tolower.c		\
      ft_strjoin.c		\
      ft_split.c		\
      ft_itoa.c			\
      ft_strtrim.c		\
      ft_substr.c		\
      ft_strdup.c		\
      ft_memcpy.c		\
      ft_calloc.c		\
      ft_bzero.c		\
	  ft_isprint.c		\
	  ft_strrchr.c		\
	  ft_strchr.c		\
	  ft_memset.c		\
	  ft_putchar_fd.c	\
	  ft_putstr_fd.c	\
	  ft_putendl_fd.c	\
	  ft_putnbr_fd.c	\
	  ft_strlcat.c		\
	  ft_strlcpy.c		\
	  ft_memccpy.c		\
	  ft_memmove.c		\
	  ft_strmapi.c		\
	  ft_memchr.c		\
	  ft_memcmp.c		\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(ARFLAGS) $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c
		$(CC) -o $@ -c $< $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all 
