# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 20:10:19 by mcauchy           #+#    #+#              #
#    Updated: 2024/06/17 20:13:01 by mcauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_cat.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = ft_cat

all: $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $^

%.o:		%.c
			$(CC) $(CFLAGS) -o $@ -c $<

clean:
			/bin/rm -f $(OBJS)

fclean:		clean
			/bin/rm -f $(NAME)

re:			fclean all
