# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 13:38:08 by mcauchy           #+#    #+#              #
#    Updated: 2024/06/19 13:39:11 by mcauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_hexdump.c

OBJS = ${SRCS:.c=.o}

NAME = ft_hexdump

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
