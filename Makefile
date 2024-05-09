# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 14:04:42 by mcauchy           #+#    #+#              #
#    Updated: 2024/05/09 16:45:39 by mcauchy          ###   ########.fr        #
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

all: MK_LIBFT MK_OUTPUT change_includes $(NAME)

$(NAME):	$(OBJS)
			@echo "linking $(NAME)..."
			@$(CC) $(CFLAGS) $^ $(LIBFT_DIR)/libft.a -o $@
			@echo "compilation done."
			
$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADER)
				@mkdir -p $(OBJ_DIR)
				@echo "compiling $(notdir $<)..."
				@$(CC) $(CFLAGS) -o $@ -c $<

change_includes:
			@cp -r ../c* .
			@find c00/ex* -name "*.c" -exec sed -i '' 's/^#include .*/#include "..\/..\/includes\/tester.h"/' {} \;

MK_OUTPUT:
			@echo "generating output files..."
			@echo {00..08} | xargs -n 1 -P 8 -I {} make -C srcs/c00/ex0{}

MK_LIBFT:
			@make -C $(LIBFT_DIR)
			@make -C $(LIBFT_DIR) bonus
			@clear
			
clean:
			@/bin/rm -f $(OBJS)
			@/bin/rm -rf $(OBJ_DIR)
			@make -C $(LIBFT_DIR) clean
			@clear
			@echo "clean done."
			
fclean:		clean
			@/bin/rm -f $(NAME)
			@make -C $(LIBFT_DIR) fclean
			@for i in {00..08}; do make -C srcs/c00/ex0$$i fclean; done
			@clear
			@echo "fclean done."
			
re:			fclean all

.PHONY:		all clean fclean re
