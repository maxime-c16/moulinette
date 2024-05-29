# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 14:43:09 by mcauchy           #+#    #+#              #
#    Updated: 2024/05/29 14:43:15 by mcauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_is_prime.c

TESTERS = tester1.c tester2.c tester3.c tester4.c tester5.c

OBJ_DIR = .objs

OUT_DIR = output

SRCS = $(FILES)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

TESTERS_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(TESTERS:.c=.o)))

CC = gcc -w

NAME = tester

HEADER = ../../../includes/tester.h

all: $(NAME)

$(NAME):	$(OBJS) $(TESTERS_OBJS)
			@mkdir -p $(OUT_DIR)
			@j=1; \
			for i in $(TESTERS_OBJS); do \
				$(CC) $(OBJS) $$i -o $(NAME); \
				./$(NAME) > $(OUT_DIR)/$(basename $(FILES))$$j.out; \
				j=$$((j+1)); \
			done

$(OBJ_DIR)/%.o:	%.c $(HEADER)
				@mkdir -p $(OBJ_DIR)
				@$(CC) -o $@ -c $<
				
clean:
			@/bin/rm -f $(OBJS)
			@/bin/rm -rf $(OBJ_DIR)
			
fclean:		clean
			@/bin/rm -f $(NAME)
			@/bin/rm -rf $(OUT_DIR)
