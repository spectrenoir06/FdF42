# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 10:11:24 by adoussau          #+#    #+#              #
#*   Updated: 2015/05/30 16:44:07 by adoussau         ###   ########.fr       *#
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
CC		= gcc -O3

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)

MLX			= mlx/libmlx_Linux.a
MLX_LINK	= -lmlx -lXext -lX11
FLAGS		= -Wall -Wextra
SRC	+=
endif

ifeq ($(UNAME_S),Darwin)

MLX			=  mlx/libmlx_intel-mac.a
MLX_LINK	= -I /opt/X11/include/ -L/usr/X11/lib -lX11 -lXext

FLAGS		= -Wall -Wextra -Werror
SRC	+=

endif

all: $(NAME)

$(NAME): $(OBJ) $(LIB2D) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) $(LIB2D) $(MLX) -o $(NAME) $(MLX_LINK) $(FLAGS)

%.o: %.c
	$(CC) -I $(HEAD_LIBFT) -I $(HEAD_LIB2D) -o $@ -c $? $(FLAGS)

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
