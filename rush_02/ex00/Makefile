# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 18:07:56 by gt-serst          #+#    #+#              #
#    Updated: 2022/08/21 22:40:07 by gt-serst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c print_value.c ft_strncpy.c ft_strlen.c ft_putstr.c \
ft_list_insert.c ft_list_free.c ft_list_find.c ft_list_create_elem.c \
ft_is_printable.c ft_is_space.c ft_is_valid.c ft_is_digit.c \
ft_file_open.c ft_dict_in.c ft_dict_create_elem.c ft_create_dict.c \
ft_dict_clear.c ft_dict_cmp.c ft_atol.c ft_check_arg.c ft_atoi.c

HEADERS		= ft_dict.h ft_list.h ft.h

OBJS		= ${SRCS:.c=.o}

NAME		= rush-02

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
