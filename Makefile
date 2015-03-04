# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 10:11:24 by adoussau          #+#    #+#              #
#*   Updated: 2014/12/10 01:03:45 by adoussau         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME	= fdf
SRC		=	main.c \
			draw_map.c \
			draw_map_fill.c \
			readmap.c \
			palette.c \
			quit.c

LIBFT	= 	libft/libft.a
LIB2D	=	lib2d/lib2d.a
HEAD_LIBFT = libft/includes
HEAD_LIB2D = lib2d/includes


OBJ		= $(SRC:.c=.o)
CC		= gcc

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)

MLX			= libmlx.a
MLX_LINK	= -lmlx -lXext -lX11
FLAGS		= -Wall -Wextra
SRC	+=
endif

ifeq ($(UNAME_S),Darwin)

MLX			= -L/usr/X11/lib
MLX_LINK	= -lmlx -lXext -lX11

FLAGS		= -Wall -Wextra -Werror
SRC	+=

endif

all: $(NAME)

$(NAME): $(OBJ) $(LIB2D) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) $(LIB2D) $(MLX) -o $(NAME) $(MLX_LINK) $(FLAGS)

%.o: %.c
	$(CC) -I $(HEAD_LIBFT) -I $(HEAD_LIB2D) $(MLX) -o $@ -c $? $(FLAGS)

$(LIB2D):
	make -C lib2d

$(LIBFT):
	make -C libft

.PHONY: clean fclean re

clean:
	rm -f $(OBJ)
	make -C libft clean
	make -C lib2d clean

fclean: clean
	rm -f $(NAME)
	make -C lib2d fclean
	make -C lib2d fclean

re: fclean all
