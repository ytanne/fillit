/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 00:01:04 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/24 15:08:11 by yorazaye         ###   ########.fr       */
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
	int			r;

	r = 1;
	maxmin = ft_memalloc(4);
	get_maxmin((*my_tetris)->x, (*my_tetris)->y, &maxmin);
	if ((i = -1) && !ft_strcmp(updown, "up"))
	{
		if (maxmin[3] > 0)
			while (++i < 4)
				(*my_tetris)->y[i]--;
		else
			r = -1;
	}
	if ((i = -1) && !ft_strcmp(updown, "down"))
	{
		if (maxmin[1] < size - 1)
			while (++i < 4)
				(*my_tetris)->y[i]++;
		else
			r = -1;
	}
	ft_memdel((void **)&maxmin);
	return (r);
}

int				tet_move_hor(t_tetris **my_tetris, char *lefrig, int size)
{
	int			*maxmin;
	int			i;
	int			r;

	r = 1;
	maxmin = ft_memalloc(4);
	get_maxmin((*my_tetris)->x, (*my_tetris)->y, &maxmin);
	if ((i = -1) && !ft_strcmp(lefrig, "left"))
	{
		if (maxmin[2] > 0)
			while (++i < 4)
				(*my_tetris)->x[i]--;
		else
			r = -1;
	}
	if ((i = -1) && !ft_strcmp(lefrig, "right"))
	{
		if (maxmin[0] < size - 1)
			while (++i < 4)
				(*my_tetris)->x[i]++;
		else
			r = -1;
	}
	ft_memdel((void **)&maxmin);
	return (r);
}

void			tet_ipos(t_tetris *my_tetris, int size)
{
	while (tet_move_hor(&my_tetris, "left", size) == 1)
		;
	while (tet_move_ver(&my_tetris, "up", size) == 1)
		;
}

int				tet_getmax(t_tetris *my_tetris)
{
	t_tetris	*p;
	int			max_xy[2];
	int			i;

	max_xy[0] = 0;
	max_xy[1] = 0;
	p = my_tetris;
	while (p)
	{
		i = -1;
		while (++i < 4)
		{
			if (p->x[i] > max_xy[0])
				max_xy[0] = p->x[i];
			if (p->y[i] > max_xy[1])
				max_xy[1] = p->y[i];
		}
		p = p->next;
	}
	if (max_xy[0] > max_xy[1])
		return (max_xy[0]);
	else
		return (max_xy[1]);
}
