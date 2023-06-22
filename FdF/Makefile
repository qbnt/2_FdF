# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 13:26:13 by qbanet            #+#    #+#              #
#    Updated: 2023/06/22 17:36:34 by qbanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = minilibx
MINILIBX_DIR_MAC = minilibx_macos
MINILIBX = $(MINILIBX_DIR)/libmlx.a
MINILIBX_MAC = $(MINILIBX_DIR_MAC)/libmlx.a
MINILIBX_LINK = -L$(MINILIBX_DIR) -lmlx -lXext -lX11
MINILIBX_LINK_MAC = -L$(MINILIBX_DIR_MAC) -lmlx -lXext -lX11

INCLUDES = -I includes -I $(LIBFT_DIR)/includes -I $(MINILIBX_DIR)

SRC_DIR = src
SRC_FILES = main.c error.c file.c key.c mlx.c utile.c
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

mac: $(OBJ) $(MINILIBX_MAC)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX_LINK_MAC) -o $(NAME)
	@echo "$(GREEN)$(ROCKET) Compilation terminée avec succès ! $(ROCKET)$(RESET)"

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

$(MINILIBX_MAC):
	@$(MAKE) -C $(MINILIBX_DIR_MAC)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)$(CHECK) Nettoyage des fichiers objets terminé$(RESET)"

clean_mac:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR_MAC) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)$(CHECK) Nettoyage des fichiers objets terminé$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "$(GREEN)$(CHECK) Nettoyage complet terminé$(RESET)"

fclean_mac: clean_mac fclean

save: fclean
	git add .
	git commit -m "make save"
	git push

re: fclean all

.PHONY: all clean fclean re
