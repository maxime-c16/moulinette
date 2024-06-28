# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 13:04:27 by mcauchy           #+#    #+#              #
#    Updated: 2024/06/28 13:07:48 by mcauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_sort_string_tab.c tester.c

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
			@./$(NAME) test papa ok maxime melissa cauchy titi le s> $(OUT_DIR)/ft_sort_string_tab.out


$(OBJ_DIR)/%.o:	%.c $(HEADER)
				@mkdir -p $(OBJ_DIR)
				@$(CC) -o $@ -c $<

clean:
			@/bin/rm -f $(OBJS)
			@/bin/rm -rf $(OBJ_DIR)

fclean:		clean
			@/bin/rm -f $(NAME)
			@/bin/rm -rf $(OUT_DIR)
