# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 10:11:24 by adoussau          #+#    #+#              #
#    Updated: 2014/12/02 15:38:53 by adoussau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lib2d.a
SRC		=	t_pt2d.c		\
			t_pt2d_img.c	\
			t_pt3d.c		\
			t_pt3d_img.c	\
			line.c			\
			line_img.c		\
			triangle.c		\
			color.c

HEADDIR		= -I includes/ -I ../libft/includes/ -I ../mlx/

OBJ		= $(SRC:.c=.o)
CC		= gcc -O3
FLAGS	= -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -O3 $(HEADDIR) -o $@ -c $? $(FLAGS)

dyn:
	gcc -fPIC -Wall -Werror -Wextra -c $(SRC)
	gcc -fPIC -Werror -Wall -Wextra -shared -o libft.so $(OBJ)

.PHONY: clean fclean re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
