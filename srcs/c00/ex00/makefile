# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 13:57:07 by mcauchy           #+#    #+#              #
#    Updated: 2024/05/09 15:39:35 by mcauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_putchar.c tester.c

OBJ_DIR = .objs

OUT_DIR = output

SRCS = $(FILES)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

CC = gcc -w

NAME = tester

HEADER = ../../../includes/tester.h

all: $(NAME)

$(NAME):	$(OBJS)
			@$(CC) $^ -o $@
			@mkdir -p $(OUT_DIR)
			@./$(NAME) > $(OUT_DIR)/ft_putchar.out
			
			
$(OBJ_DIR)/%.o:	%.c $(HEADER)
				@mkdir -p $(OBJ_DIR)
				@$(CC) -o $@ -c $<
				
clean:
			@/bin/rm -f $(OBJS)
			@/bin/rm -rf $(OBJ_DIR)
			
fclean:		clean
			@/bin/rm -f $(NAME)
			@/bin/rm -rf $(OUT_DIR)