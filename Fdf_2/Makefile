# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 13:26:13 by qbanet            #+#    #+#              #
#    Updated: 2023/08/15 19:43:07 by qbanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = minilibx
MINILIBX = $(MINILIBX_DIR)/libmlx.a
MINILIBX_LINK = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES = -I includes -I $(LIBFT_DIR)/includes -I $(MINILIBX_DIR)

SRC_DIR = src
SRC_FILES = main.c\
			map_crea.c\
			utile.c\
			utile_2.c\
			init.c\
			key.c\
			key_move.c\
			draw.c\
			render.c\
			projection.c\
			rotate.c\
			transform.c\
			menu.c\
			color.c\
			error.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = obj
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

# Couleurs
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

# Emojis
CHECK = ✔️
ROCKET = 🚀︎

all: $(NAME)

$(NAME): $(OBJ) $(MINILIBX)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX_LINK) -o $(NAME)
	@echo "$(GREEN)$(ROCKET) Compilation terminée avec succès ! $(ROCKET)$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(YELLOW)$(CHECK) $(notdir $@) compilé$(RESET)"

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)$(CHECK) Nettoyage des fichiers objets terminé$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "$(GREEN)$(CHECK) Nettoyage complet terminé$(RESET)"

save: fclean
	git add .
	git commit -m "make save"
	git push

re: fclean all

.PHONY: all clean fclean re
