# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 14:04:42 by mcauchy           #+#    #+#              #
#    Updated: 2024/05/27 21:03:57 by mcauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = main.c

SRC_DIR = srcs

OBJ_DIR = .objs

LIBFT_DIR = libft

SRCS = $(addprefix $(SRC_DIR)/, $(FILES))

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

CC = gcc -fsanitize=address -g3

# CFLAGS = -Wall -Wextra -Werror

NAME = moulinette

HEADER = includes/moulinette.h

# Color codes
RESET = \033[0m
BOLD = \033[1m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m

all: MK_LIBFT $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $^ $(LIBFT_DIR)/libft.a -o $@
	@echo "$(GREEN)compilation done.$(RESET)"
			
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)compiling $(notdir $<)...$(RESET)"
	@$(CC) $(CFLAGS) -o $@ -c $<

C00: all
	@echo "$(BLUE)compiling c00...$(RESET)"
	@echo {00..08} | xargs -n 1 -P 8 -I {} make -C srcs/c00/ex0{} > /dev/null
	@echo "$(BLUE)copying student c00 folder into moulinette/...$(RESET)"
	@cp -r ../c00 .
	@echo "$(BLUE)changing include path in ft_*.c files...$(RESET)"
	@find c00/ex* -name "*.c" -exec sed -i '' 's/^#include .*/#include "..\/..\/includes\/moulinette.h"/' {} \;
	@echo "$(BLUE)generating output files...$(RESET)"
	@echo {00..08} | xargs -n 1 -P 8 -I {} make -C srcs/c00/ex0{} > /dev/null
	@echo "usage: $(BOLD)./moulinette $(RED)[path to c00/exXX/ft_*.c]$(RESET)"

C01: all
	@echo "$(BLUE)compiling c01...$(RESET)"
	@echo {00..08} | xargs -n 1 -P 8 -I {} make -C srcs/c01/ex0{} > /dev/null
	@echo "$(BLUE)copying student c01 folder into moulinette/...$(RESET)"
	@cp -r ../c01 .
	@echo "$(BLUE)changing include path in ft_*.c files...$(RESET)"
	@find c01/ex* -name "*.c" -exec sed -i '' 's/^#include .*/#include "..\/..\/includes\/moulinette.h"/' {} \;
	@echo "$(BLUE)generating output files...$(RESET)"
	@echo {00..08} | xargs -n 1 -P 8 -I {} make -C srcs/c01/ex0{} > /dev/null
	@echo "usage: $(BOLD)./moulinette $(RED)[path to c01/exXX/ft_*.c]$(RESET)"
	
C02: all
	@echo "$(BLUE)compiling c02...$(RESET)"
	@echo {00..09} | xargs -n 1 -P 2 -I {} make -C srcs/c02/ex0{} > /dev/null
	@echo {10..12} | xargs -n 1 -P 1 -I {} make -C srcs/c02/ex{} > /dev/null
	@echo "$(BLUE)copying student c02 folder into moulinette/...$(RESET)"
	@cp -r ../c02 .
	@echo "$(BLUE)changing include path in ft_*.c files...$(RESET)"
	@find c02/ex* -name "*.c" -exec sed -i '' 's/^#include .*/#include "..\/..\/includes\/moulinette.h"/' {} \;
	@echo "$(BLUE)generating output files...$(RESET)"
	@echo {00..09} | xargs -n 1 -P 2 -I {} make -C srcs/c02/ex0{} > /dev/null
	@echo {10..12} | xargs -n 1 -P 1 -I {} make -C srcs/c02/ex{} > /dev/null
	@echo "usage: $(BOLD)./moulinette $(RED)[path to c02/exXX/ft_*.c]$(RESET)"

MK_LIBFT:
	@make -C $(LIBFT_DIR)
	@make -C $(LIBFT_DIR) bonus
	@clear
			
clean:
	@/bin/rm -f $(OBJS)
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@clear
	@echo "$(GREEN)clean done.$(RESET)"
			
fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@/bin/rm -rf c*/
	@/bin/rm -rf trace
	@for i in {00..08}; do make -C srcs/c00/ex0$$i fclean > /dev/null; done #c00
	@for i in {00..08}; do make -C srcs/c01/ex0$$i fclean > /dev/null; done #c01
	@for i in {00..09}; do make -C srcs/c02/ex0$$i fclean > /dev/null; done #c02
	@for i in {10..12}; do make -C srcs/c02/ex$$i fclean > /dev/null; done #c02
	@clear
	@echo "$(GREEN)fclean done.$(RESET)"
			
re: fclean all

.PHONY: all clean fclean re
