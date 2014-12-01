# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 10:11:24 by adoussau          #+#    #+#              #
#    Updated: 2014/12/01 15:57:53 by adoussau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
SRC		=	 main.c \
			fdf.c

LIBFT	= 	libft/includes
LIB2D	=	lib2d/includes

OBJ		= $(SRC:.c=.o)
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -L/usr/X11/lib -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a lib2d/lib2d.a
	@$(CC) -O3 -I $(LIBFT) -I $(LIB2D) libft/libft.a lib2d/lib2d.a -o $(NAME) $(OBJ) $(FLAGS)

%.o: %.c
	@$(CC) -O3 -I $(LIBFT) -I $(LIB2D)  -o $@ -c $? $(FLAGS)

lib2d/lib2d.a:
	make -C lib2d

libft/libft.a:
	make -C libft

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)
	@make -C libft clean
	@make -C lib2d clean

fclean: clean
	@rm -f $(NAME)
	make -C lib2d fclean
	make -C lib2d fclean

re: fclean all
