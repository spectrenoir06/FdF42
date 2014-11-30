# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 10:11:24 by adoussau          #+#    #+#              #
#    Updated: 2014/11/30 19:52:23 by adoussau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
SRC		= main.c

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

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
