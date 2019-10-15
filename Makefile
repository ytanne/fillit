# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 09:39:05 by yorazaye          #+#    #+#              #
#    Updated: 2019/10/14 23:50:43 by yorazaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit ft_checks tetris_struct

F_C = $(addsuffix .c, $(SRC))

F_O = $(addsuffix .o, $(SRC))

F_S = $(patsubst %, src/%, $(F_C))

F_I = libft/includes -I includes

FLAGS = -Wall -Wextra -Werror -L libft -lft -g

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(F_S) -I $(F_I) $(FLAGS)

run:
	./$(NAME) test_files/test3.fillit

debug:
	lldb ./$(NAME) test_files/test0.fillit

clean:
	rm -f $(F_O)

fclean: clean
	rm -rf $(NAME) $(NAME).dSYM

re: fclean all
