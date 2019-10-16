/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 00:01:04 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/16 08:35:22 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

static void		get_maxmin(int *x, int *y, int **maxmin)
{
	int			i;

	(*maxmin)[0] = 0; //x max
	(*maxmin)[1] = 0; //y max
	(*maxmin)[2] = 4; //x min
	(*maxmin)[3] = 4; //y min
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

int				tet_move_ver(t_tetris **my_tetris, char *updown)
{
	int			*maxmin;
	int			i;
	
	maxmin = ft_memalloc(4);
	i = -1;
	get_maxmin((*my_tetris)->x, (*my_tetris)->y, &maxmin);
	if (!ft_strcmp(updown, "up"))
	{
		if (maxmin[3] > 0)
			while (++i < 4)
				(*my_tetris)->y[i]--;
		else
			return (-1);
	}
	if (!ft_strcmp(updown, "down"))
	{
		if (maxmin[1] < 3)
			while (++i < 4)
				(*my_tetris)->y[i]++;
		else
			return (-1);
	}
	ft_memdel((void **)&maxmin);
	return (1);
}

int				tet_move_hor(t_tetris **my_tetris, char *lefrig)
{
	int			*maxmin;
	int			i;
	
	maxmin = ft_memalloc(4);
	i = -1;
	get_maxmin((*my_tetris)->x, (*my_tetris)->y, &maxmin);
	if (!ft_strcmp(lefrig, "left"))
	{
		if (maxmin[2] > 0)
			while (++i < 4)
				(*my_tetris)->x[i]--;
		else
			return (-1);
	}
	if (!ft_strcmp(lefrig, "right"))
	{
		if (maxmin[0] < 3)
			while (++i < 4)
				(*my_tetris)->x[i]++;
		else
			return (-1);
	}
	ft_memdel((void **)&maxmin);
	return (1);
}

void			tet_ipos(t_tetris **my_tetris)
{
	while (tet_move_hor(my_tetris, "left") == 1)
		;
	while (tet_move_ver(my_tetris, "up") == 1)
		;
}
/* Tested function for deleting whole tetris list
void			tet_del(t_tetris **my_tetris)d
{
	t_tetris	*tmp;

	while (*my_tetris)
	{
		tmp = *my_tetris;
		ft_memdel((void **)&(*my_tetris));
		*my_tetris = tmp->next;
	}
}
*/
/*
int		main(void)
{
	t_tetris	*my_tetris;
	int			x[4] = {2, 3, 1, 2};
	int			y[4] = {1, 1, 2, 2};

	my_tetris = tet_new(x, y);
	tet_print_coords(my_tetris);
	tet_print_gui(my_tetris, 4, '#');
	ft_putstr("=======\n");
	tet_ipos(&my_tetris);
	tet_print_coords(my_tetris);
	tet_print_gui(my_tetris, 4, '#');
	ft_putstr("=======\n");
	tet_ipos(&my_tetris);
	tet_print_coords(my_tetris);
	tet_print_gui(my_tetris, 4, '#');
	ft_putstr("=======\n");
	return (0);
}*/
