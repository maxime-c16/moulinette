# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 17:08:15 by mcauchy           #+#    #+#              #
#    Updated: 2024/06/16 17:21:42 by mcauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c

SRCS_DIR = srcs

SRCS = $(addprefix $(SRCS_DIR)/, $(FILES))

OBJS = $(addprefix $(SRCS_DIR)/, $(notdir $(SRCS:.c=.o)))

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

HEADER = includes/ft.h

all: $(NAME)

$(NAME):	$(OBJS)
			ar rcs $@ $^
			
$(SRCS_DIR)/%.o:	$(SRCS_DIR)/%.c $(HEADER)
					$(CC) $(CFLAGS) -o $@ -c $<
					
clean:
			/bin/rm -f $(OBJS)
			
fclean:		clean
			/bin/rm -f $(NAME)
			
re:			fclean all
