# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 16:42:14 by mcauchy           #+#    #+#              #
#    Updated: 2024/06/03 16:43:27 by mcauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_print_params.c

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
			@./$(NAME) > $(OUT_DIR)/ft_print_params1.out
			@./$(NAME) a b c > $(OUT_DIR)/ft_print_params2.out
			
			
			
$(OBJ_DIR)/%.o:	%.c $(HEADER)
				@mkdir -p $(OBJ_DIR)
				@$(CC) -o $@ -c $<
				
clean:
			@/bin/rm -f $(OBJS)
			@/bin/rm -rf $(OBJ_DIR)
			
fclean:		clean
			@/bin/rm -f $(NAME)
			@/bin/rm -rf $(OUT_DIR)
