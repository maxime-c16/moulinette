# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 14:04:34 by mcauchy           #+#    #+#              #
#    Updated: 2024/06/27 17:08:02 by mcauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	main.c do-op.c

OBJS_DIR		=	.objs

OBJS			=	$(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

HEADER			=	../../../includes/tester.h

CC				=	clang

NAME			=	do-op

all				:	$(NAME)

$(NAME)			:	$(OBJS)
					$(CC) $^ -o $@

$(OBJS_DIR)/%.o	:	%.c	$(HEADER)
					@mkdir -p $(OBJS_DIR)
					@$(CC) -o $@ -c $<

clean			:
					/bin/rm -rf $(OBJS)
					/bin/rm -rf $(OBJS_DIR)

fclean			:	clean
					/bin/rm -rf $(NAME)

re				:	fclean all

