# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 17:09:44 by scha              #+#    #+#              #
#    Updated: 2021/06/10 17:18:33 by scha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server

NAME2 = client

all :
	make -C libft
	gcc -Wall -Wextra -Werror server_main.c libft/libft.a -o $(NAME1)
	gcc -Wall -Wextra -Werror client_main.c libft/libft.a -o $(NAME2)

clean :
	make clean -C libft 
	rm -rf client.o server.o

fclean : clean
	make fclean -C libft
	rm -rf $(NAME1) $(NAME2)

re : fclean all