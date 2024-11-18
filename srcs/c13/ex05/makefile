# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 15:18:08 by mcauchy           #+#    #+#              #
#    Updated: 2024/06/30 18:15:23 by mcauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = btree_search_item.c tester.c

OBJ_DIR = .objs

OUT_DIR = output

SRCS = $(FILES)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

CC = gcc -fsanitize=address -g3 -Wall -Wextra -Werror

NAME = tester

HEADER = ../../../includes/tester.h

all: $(NAME)

$(NAME):	$(OBJS)
			@$(CC) $^ -o $@
			@mkdir -p $(OUT_DIR)
			@./$(NAME) > $(OUT_DIR)/btree_search_item.out


$(OBJ_DIR)/%.o:	%.c $(HEADER)
				@mkdir -p $(OBJ_DIR)
				@$(CC) -o $@ -c $<

clean:
			@/bin/rm -f $(OBJS)
			@/bin/rm -rf $(OBJ_DIR)

fclean:		clean
			@/bin/rm -f $(NAME)
			@/bin/rm -rf $(OUT_DIR)
