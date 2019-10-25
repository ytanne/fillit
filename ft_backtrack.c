/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:56:48 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/24 17:21:03 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>

static int	insert_tetris(t_tetris *te, char ***res, int *i, int n)
{
	if (++(*i) == 4)
		return (1);
	else
	{
		if ((*res)[te->y[*i]][te->x[*i]] == '.')
			(*res)[te->y[*i]][te->x[*i]] = te->letter;
		else
			return (0);
		if (insert_tetris(te, res, i, n) == 1)
			return (1);
		else
		{
			if (*i > 0)
				--(*i);
			(*res)[te->y[*i]][te->x[*i]] = '.';
		}
	}
	return (0);
}

static int	remove_tetris(t_tetris *te, char ***res, int *i, int n)
{
	if (++(*i) == 4)
		return (1);
	else
	{
		if ((*res)[te->y[*i]][te->x[*i]] == te->letter)
			(*res)[te->y[*i]][te->x[*i]] = '.';
		else
			return (0);
		if (remove_tetris(te, res, i, n) == 1)
			return (1);
		else
		{
			if (*i > 0)
				--(*i);
			(*res)[te->y[*i]][te->x[*i]] = te->letter;
		}
	}
	return (0);
}

static int	move_tetris(t_tetris *t, int n)
{
	if (tet_move_hor(&t, "right", n) == 1)
		return (1);
	else
	{
		while (tet_move_hor(&t, "left", n) > 0)
			;
		if (tet_move_ver(&t, "down", n) == 1)
			return (1);
	}
	tet_ipos(t, n);
	return (0);
}

static int	start_pls(t_tetris *t, char **field, int n)
{
	int		i;

	while (t)
	{
		i = -1;
		if (insert_tetris(t, &field, &i, n))
			t = t->next;
		else if (move_tetris(t, n) == 1)
			;
		else
		{
			i = -1;
			t = t->prev;
			remove_tetris(t, &field, &i, n);
			while (move_tetris(t, n) == 0)
			{
				if (t->letter == 'A')
					return (0);
				t = t->prev;
				i = -1;
				remove_tetris(t, &field, &i, n);
			}
		}
	}
	return (1);
}

void		field_init(t_tetris *t)
{
	char		**field;
	int			n;
	int			solved;
	int			i;
	t_tetris	*ptr;

	solved = 0;
	ptr = t;
	while (ptr)
	{
		tet_ipos(ptr, 4);
		ptr = ptr->next;
	}
	n = tet_getmax(t) + 1;
	while (solved == 0)
	{
		field = create_field(n);
		if ((solved = start_pls(t, field, n)))
			print_field(field, n);
		delete_field(&field, n);
		if (solved == 0)
			n++;
	}
}
