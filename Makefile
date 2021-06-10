# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 17:09:44 by scha              #+#    #+#              #
#    Updated: 2021/06/10 19:00:01 by scha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server

NAME2 = client

NAME3 = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all : $(NAME3) $(NAME2) $(NAME1)

%.o : %.c
		$(CC) $(FLAGS) $< -c


$(NAME3) :
		make -C libft

$(NAME1) : server_main.o
		$(CC) server_main.o ./libft/libft.a -o $@

$(NAME2) : client_main.o
		$(CC) client_main.o ./libft/libft.a -o $@

clean :
	make clean -C libft 
	rm -rf client_main.o server_main.o

fclean :
	make fclean -C libft
	rm -rf client_main.o server_main.o
	rm -rf $(NAME1) $(NAME2)

re : fclean all
