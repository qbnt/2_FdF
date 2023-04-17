# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 13:26:13 by qbanet            #+#    #+#              #
#    Updated: 2023/04/17 13:45:05 by qbanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/fdf.c src/utile.c

LIBFT = libft/libft.a
LIBFT_DIR = libft
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

INCLUDES = -Iincludes -I$(LIBFT_DIR)/includes

OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)⏳ Linking FdF...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) -o $(NAME)
	@echo "$(GREEN)✅ FdF created!$(RESET)"

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJS_DIR)
	@echo "$(GREEN)🪠 Object files cleaned!$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "$(GREEN)🪠 Client and Server executables cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
