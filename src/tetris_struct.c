/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 21:49:19 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/14 21:19:10 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

t_tetris		*tet_new(int *x, int *y)
{
	t_tetris	*my_tetris;
	int		i;

	i = -1;
	if (!(my_tetris = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	if (!x || !y)
		return (NULL);
	while (++i < 4)
		my_tetris->x[i] = x[i];
	i = -1;
	while (++i < 4)
		my_tetris->y[i] = y[i];
	my_tetris->next = NULL;
	return (my_tetris);
}

void			tet_add_to_end(t_tetris **my_tetris, t_tetris *part)
{
	t_tetris	*ptr;

	ptr = *my_tetris;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = part;
}

void			tet_print_coords(t_tetris *some_tetris)
{
	int			i;
	t_tetris	*my_tetris;

	if (!some_tetris)
		return ;
	my_tetris = some_tetris;
	while (my_tetris)
	{
		i = -1;
		while (++i < 4)
		{
			ft_putnbr(my_tetris->x[i]);
			ft_putchar(' ');
			ft_putnbr(my_tetris->y[i]);
			ft_putchar('\n');
		}
		if (my_tetris->next)
			ft_putstr("------------\n");
		my_tetris = my_tetris->next;
	}
}
