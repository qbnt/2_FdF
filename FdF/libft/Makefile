# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 12:04:16 by qbanet            #+#    #+#              #
#    Updated: 2023/05/23 09:25:20 by qbanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
ARFLAGS = -crs

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAG = -rf

INCLUDES = -I./includes
SRC_DIR = src
OBJ_DIR = obj

SRCS = $(whildcard *.c)
SRC = $(addprefix $(SRC_DIR)/,$(SRCS))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all : $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJ)
	@$(AR) $(ARFLAGS) $@ $^
	@echo "$(GREEN)libft.a created!$(RESET)"

clean :
	@$(RM) $(RMFLAG) $(OBJ_DIR)
	@echo "$(YELLOW)Object files removed!$(RESET)"

fclean : clean
	@$(RM) $(RMFLAG) $(NAME)
	@echo "$(YELLOW)libft.a removed!$(RESET)"

re : fclean all

.PHONY: all clean fclean re
