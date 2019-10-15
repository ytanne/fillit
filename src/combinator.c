/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:49:13 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/15 14:06:22 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		combinator(t_tetris **my_tetris)
{
	t_tetris	*ptr;
	int 		i;

	ptr = *my_tetris;
	tet_move_hor(&ptr, "left");
	tet_move_ver(&ptr, "up");
	tet_print_coords(ptr);
}

int		main
