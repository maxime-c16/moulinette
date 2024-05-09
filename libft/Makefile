# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 17:39:45 by mcauchy           #+#    #+#              #
#    Updated: 2022/11/18 15:26:48 by yschecro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_OBJ			=	../.objs

SRCS			=	ft_atoi.c ft_isascii.c ft_memccpy.c ft_memset.c ft_strlcpy.c ft_strrchr.c \
					ft_bzero.c ft_isdigit.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlen.c ft_strtrim.c \
					ft_calloc.c ft_isprint.c ft_memcmp.c  ft_putendl_fd.c ft_strdup.c  ft_strmapi.c ft_substr.c \
					ft_isalnum.c ft_itoa.c ft_memcpy.c ft_putnbr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c \
					ft_isalpha.c ft_memmove.c ft_putstr_fd.c ft_strlcat.c ft_strnstr.c ft_toupper.c ft_strcmp.c \
					ft_strjoin_char.c ft_strcpy.c ft_str_is_numeric.c \

BONUS			=	ft_lstnew.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c

BONUS_OBJS		=	$(addprefix $(DIR_OBJ)/, $(notdir $(BONUS:.c=.o)))

NAME			=	libft.a

OBJ				=	$(addprefix $(DIR_OBJ)/, $(notdir $(SRCS:.c=.o)))

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -g3

HEADER			=	../includes/libft.h

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					@echo "Creating libft.a"
					@ar rc $@ $^
					@ranlib $@

$(DIR_OBJ)/%.o	:	%.c $(HEADER)
					@mkdir -p $(@D)
					@echo "Compiling $(notdir $<)..."
					@$(CC) $(CFLAGS) -o $@ -c $<

clean			:
					@/bin/rm -f $(OBJ)
					@/bin/rm -rf $(DIR_OBJ)
					@/bin/rm -f $(BONUS_OBJS)

fclean			:	clean
					@/bin/rm -f $(NAME)

re				:	fclean all

bonus			:	$(OBJS) $(BONUS_OBJS)
					@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY			:	all clean norme fclean re
