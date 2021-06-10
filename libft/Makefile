# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 17:14:55 by scha              #+#    #+#              #
#    Updated: 2021/06/10 17:17:39 by scha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS=ft_atoi.c ft_putchar.c ft_putnbr.c ft_putstr.c\

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re