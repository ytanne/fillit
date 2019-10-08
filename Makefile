# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 09:39:05 by yorazaye          #+#    #+#              #
#    Updated: 2019/10/08 10:12:53 by yorazaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

F_C = $(addsuffix .c, $(NAME))

F_O = $(addsuffix .o, $(F_O))

F_I = libft/includes

FLAGS = -Wall -Wextra -Werror -L libft -lft -g

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(F_C) -I $(F_I) $(FLAGS)

clean:
	rm -f $(F_O)

fclean: clean

re: fclean all
