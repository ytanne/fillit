# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 20:02:52 by yorazaye          #+#    #+#              #
#    Updated: 2019/10/22 15:17:56 by mstupnik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

F = ft_backtrack ft_tetris tetris_manipulation additional ft_checks fillit

F_C = $(addsuffix .c, $(F))

F_O = $(addsuffix .o, $(F))

I1 = libft/includes

I2 = fillit.h

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(F_C) -I $(I2) -I $(I1) -L libft -lft

clean:
	rm -f $(F_O)

fclean: clean
	rm -rf $(NAME) $(NAME).dSYM

re: fclean all
