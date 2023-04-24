# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 13:26:13 by qbanet            #+#    #+#              #
#    Updated: 2023/04/24 11:28:53 by qbanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -Iincludes -Ilibft/includes -Iminilibx-linux
LFLAGS = -Llibft -lft -Lminilibx-linux -lmlx -lXext -lX11 -lm

# Fichiers source et objet
SRCS = src/fdf.c src/utile.c
OBJS = $(SRCS:.c=.o)

# Règles de compilation
all: libft/libft.a minilibx-linux/libmlx.a fdf

libft/libft.a:
	cd libft && make

minilibx-linux/libmlx.a:
	cd minilibx-linux && make

fdf: $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJS) -o fdf

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	cd libft && make clean
	cd minilibx-linux && make clean
	rm -f $(OBJS)

fclean: clean
	cd libft && make fclean
	rm -f minilibx-linux/libmlx.a
	rm -f fdf

re: fclean all

.PHONY: all clean fclean re
