# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/05 12:40:04 by mcauchy           #+#    #+#              #
#    Updated: 2024/06/05 12:42:56 by mcauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_sort_params.c

OBJ_DIR = .objs
 
OUT_DIR = output

SRCS = $(FILES)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

CC = gcc

NAME = tester

HEADER = ../../../includes/tester.h

all: $(NAME)

$(NAME):	$(OBJS)
			@$(CC) $^ -o $@
			@mkdir -p $(OUT_DIR)
			@./$(NAME) > $(OUT_DIR)/ft_sort_params1.out
			@./$(NAME) "aaa" "bbb" "ccc" > $(OUT_DIR)/ft_sort_params2.out
			@./$(NAME) "ccc" "bbb" "aaa" > $(OUT_DIR)/ft_sort_params3.out
			@./$(NAME) "bbb" "aaa" "ccc" > $(OUT_DIR)/ft_sort_params4.out
			@./$(NAME) "aaa" "ccc" "bbb" > $(OUT_DIR)/ft_sort_params5.out
			@./$(NAME) "ccc" "aaa" "bbb" > $(OUT_DIR)/ft_sort_params6.out
			@./$(NAME) "test" "testing" "tester" "testest" "tested" "TESTER" "TEST42"> $(OUT_DIR)/ft_sort_params7.out
			
			
			
$(OBJ_DIR)/%.o:	%.c $(HEADER)
				@mkdir -p $(OBJ_DIR)
				@$(CC) -o $@ -c $<
				
clean:
			@/bin/rm -f $(OBJS)
			@/bin/rm -rf $(OBJ_DIR)
			
fclean:		clean
			@/bin/rm -f $(NAME)
			@/bin/rm -rf $(OUT_DIR)
