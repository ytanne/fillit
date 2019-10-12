# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 09:39:05 by yorazaye          #+#    #+#              #
#    Updated: 2019/10/11 12:21:03 by yorazaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

F_C = $(addsuffix .c, $(NAME))

F_O = $(addsuffix .o, $(NAME))

F_I = libft/includes

FLAGS = -Wall -Wextra -Werror -L libft -lft -g

all: $(NAME)

$(NAME):
	gcc -o $(NAME) src/$(F_C) -I $(F_I) $(FLAGS)

clean:
	rm -f $(F_O)

fclean: clean
	rm -f $(NAME)

re: fclean all
