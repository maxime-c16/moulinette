# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 19:56:01 by mcauchy           #+#    #+#              #
#    Updated: 2024/06/17 19:56:50 by mcauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_display_file.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = ft_display_file

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
