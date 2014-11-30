# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 10:11:24 by adoussau          #+#    #+#              #
#    Updated: 2014/11/30 20:06:41 by adoussau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lib2d.a
SRC		=	t_pt2d.c \
			t_pt3d.c \
			line.c	\
			color.c

HEADDIR	= includes/

OBJ		= $(SRC:.c=.o)
CC		= gcc
FLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) -O3 -I $(HEADDIR) -o $@ -I . -c $? $(FLAGS)

dyn: 
	@gcc -fPIC -Wall -Werror -Wextra -c $(SRC)
	@gcc -fPIC -Werror -Wall -Wextra -shared -o libft.so $(OBJ)

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
