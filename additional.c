/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:37:30 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/24 21:30:09 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

void		new_int_arr(int ***coords)
{
	(*coords) = ft_memalloc(2);
	(*coords)[0] = ft_memalloc(4);
	(*coords)[1] = ft_memalloc(4);
}

void		get_x_coord(char *line, int ***coords)
{
	int		xy[2];
	int		j;
	int		k;

	xy[0] = 0;
	xy[1] = 0;
	j = 0;
	k = -1;
	new_int_arr(coords);
	while (line[++k] && *coords)
	{
		if (line[k] == '#')
		{
			(*coords)[0][j] = xy[0];
			(*coords)[1][j++] = xy[1];
		}
		if (line[k] == '\n')
		{
			xy[0] = 0;
			xy[1]++;
		}
		else
			xy[0]++;
	}
}

char		**create_field(int n)
{
	int		i;
	char	**field;

	i = -1;
	field = (char **)malloc(sizeof(char *) * (n + 1));
	while (++i < n)
	{
		field[i] = ft_strnew(n);
		ft_memset(field[i], '.', n);
		field[i][n] = '\0';
	}
	field[n] = "\0";
	return (field);
}

void		print_field(char **field, int n)
{
	int		i;

	i = -1;
	while (++i < n)
	{
		ft_putstr(field[i]);
		ft_putchar('\n');
	}
}

int			init_size_pose(t_tetris **t)
{
	t_tetris	*p;
	int			size;
	int			r;

	p = *t;
	size = 0;
	r = 1;
	while (p)
	{
		tet_ipos(p, 4);
		size++;
		p = p->next;
	}
	size *= 4;
	while (r * r < size)
		r++;
	return (r);
}
