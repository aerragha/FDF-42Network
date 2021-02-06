# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aerragha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/17 15:24:57 by aerragha          #+#    #+#              #
#    Updated: 2018/12/19 10:18:04 by aerragha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

PATH_INC = ./libft/includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = src/fdf.h

SRC = src/main.c \
	  src/bresenham.c \
	  src/draw_par.c \
	  src/draw_iso.c \
	  src/key_pressed.c \
	  src/functions.c \
	  src/read_file.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@/bin/rm -f *.o

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
