# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 20:02:52 by yorazaye          #+#    #+#              #
#    Updated: 2019/10/22 18:28:04 by yorazaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

F = ft_backtrack ft_tetris tetris_manipulation additional ft_checks fillit leakage_deal

F_C = $(addsuffix .c, $(F))

F_O = $(addsuffix .o, $(F))

I1 = libft/includes

I2 = fillit.h

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -o $(NAME) $(F_C) -I $(I2) -I $(I1) -L libft -lft

debug:
	gcc -o $(NAME) $(F_C) -I $(I2) -I $(I1) -L libft -lft -g

clean:
	rm -f libft/*.o
	rm -f $(F_O)

fclean: clean
	rm -f libft/libft.a
	rm -rf $(NAME)

re: fclean all
