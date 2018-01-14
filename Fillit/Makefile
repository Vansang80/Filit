# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pasnguye <pasnguye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/24 19:44:28 by pasnguye          #+#    #+#              #
#    Updated: 2017/12/15 10:45:44 by pasnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c\
	security.c\
	check_buffer.c\
	check_piece.c\
	map_management.c\
	find_solution.c\
	link.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make  -C ./Libft
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc -o $(NAME) $(OBJ) Libft/libft.a

clean:
	make -C ./Libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C ./Libft fclean
	rm -rf $(NAME) 

re: fclean all

.PHONY: all clean fclean re
