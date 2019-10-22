/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 00:01:04 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/22 15:11:49 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

static void		get_maxmin(int *x, int *y, int **maxmin)
{
	int			i;

	(*maxmin)[0] = 0;
	(*maxmin)[1] = 0;
	(*maxmin)[2] = 4;
	(*maxmin)[3] = 4;
	i = -1;
	while (++i < 4)
	{
		if (x[i] > (*maxmin)[0])
			(*maxmin)[0] = x[i];
		if (x[i] < (*maxmin)[2])
			(*maxmin)[2] = x[i];
		if (y[i] > (*maxmin)[1])
			(*maxmin)[1] = y[i];
		if (y[i] < (*maxmin)[3])
			(*maxmin)[3] = y[i];
	}
}

int				tet_move_ver(t_tetris **my_tetris, char *updown, int size)
{
	int			*maxmin;
	int			i;

	maxmin = ft_memalloc(4);
	get_maxmin((*my_tetris)->x, (*my_tetris)->y, &maxmin);
	if ((i = -1) && !ft_strcmp(updown, "up"))
	{
		if (maxmin[3] > 0)
			while (++i < 4)
				(*my_tetris)->y[i]--;
		else
			return (-1);
	}
	if ((i = -1) && !ft_strcmp(updown, "down"))
	{
		if (maxmin[1] < size - 1)
			while (++i < 4)
				(*my_tetris)->y[i]++;
		else
			return (-1);
	}
	ft_memdel((void **)&maxmin);
	return (1);
}

int				tet_move_hor(t_tetris **my_tetris, char *lefrig, int size)
{
	int			*maxmin;
	int			i;

	maxmin = ft_memalloc(4);
	get_maxmin((*my_tetris)->x, (*my_tetris)->y, &maxmin);
	if ((i = -1) && !ft_strcmp(lefrig, "left"))
	{
		if (maxmin[2] > 0)
			while (++i < 4)
				(*my_tetris)->x[i]--;
		else
			return (-1);
	}
	if ((i = -1) && !ft_strcmp(lefrig, "right"))
	{
		if (maxmin[0] < size - 1)
			while (++i < 4)
				(*my_tetris)->x[i]++;
		else
			return (-1);
	}
	ft_memdel((void **)&maxmin);
	return (1);
}

void			tet_ipos(t_tetris *my_tetris, int size)
{
	while (tet_move_hor(&my_tetris, "left", size) == 1)
		;
	while (tet_move_ver(&my_tetris, "up", size) == 1)
		;
}
