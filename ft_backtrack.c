/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:56:48 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/20 16:29:18 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>

static int	insert_tetris(t_tetris *te, char ***res, int *i, int n)
{
	if (++(*i) == 4)
	{
		ft_putstr("placing tetris\n"); //Delete me !
		print_field(*res, n); //Delete me !
		ft_putstr("==========\n"); //Delete me !
		return (1);
	}
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
	{
		ft_putstr("removing tetris\n"); //Delete me!
		print_field(*res, n); //Delete me !
		ft_putstr("==========\n"); //Delete me !
		return (1);
	}
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

static int	start_pls(t_tetris *t, char **field)
{
	int		r;
	int		n;
	int		i;

	r = 0;
	n = ft_strlen(*field);
	while (t)
	{
		i = -1;
		if (insert_tetris(t, &field, &i, n))
		{
			t = t->next;
			r = 1;
		}
		else if (move_tetris(t, n) == 1)
			r = 1;
		else
		{
			i = -1;
			t = t->prev;
			remove_tetris(t, &field, &i, n);
			r = 0;
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
	return (r);
}

void		field_init(t_tetris	*t)
{
	char	**field;
	int		n;
	int		solved;
	int		i;

	n = 4;
	solved = 0;
	while (solved == 0)
	{
		field = create_field(n);
		if ((solved = start_pls(t, field)))
			print_field(field, n);
		delete_field(&field, n);
		if (solved == 0)
			n++;
	}
}

int			main(void)
{
	t_tetris	*my_tetris0;
	t_tetris	*my_tetris1;
	t_tetris	*my_tetris2;
	t_tetris	*my_tetris3;
	t_tetris	*my_tetris4;
	t_tetris	*my_tetris5;
	t_tetris	*my_tetris6;
	t_tetris	*my_tetris7;
	t_tetris	*t;

	int			x[4] = {3, 3, 3, 3};
	int			y[4] = {0, 1, 2, 3};
	int			x1[4] = {0, 1, 2, 3};
	int			y1[4] = {3, 3, 3, 3};
	int			x2[4] = {1, 2, 3, 3};
	int			y2[4] = {0, 0, 0, 1};
	int			x3[4] = {2, 3, 1, 2};
	int			y3[4] = {1, 1, 2, 2};
	int			x4[4] = {1, 2, 1, 2};
	int			y4[4] = {1, 1, 2, 2};
	int			x5[4] = {0, 1, 1, 2};
	int			y5[4] = {2, 2, 3, 3};
	int			x6[4] = {0, 1, 1, 1};
	int			y6[4] = {0, 0, 1, 2};
	int			x7[4] = {0, 1, 2, 1};
	int			y7[4] = {1, 1, 1, 2};

	my_tetris0 = ft_tetris_new(x, y, 'A');
	my_tetris1 = ft_tetris_new(x1, y1, 'B');
	my_tetris2 = ft_tetris_new(x2, y2, 'C');
	my_tetris3 = ft_tetris_new(x3, y3, 'D');
	my_tetris4 = ft_tetris_new(x4, y4, 'E');
	my_tetris5 = ft_tetris_new(x5, y5, 'F');
	my_tetris6 = ft_tetris_new(x6, y6, 'G');
	my_tetris7 = ft_tetris_new(x7, y7, 'H');
	ft_tet_to_end(&my_tetris0, my_tetris1);
	ft_tet_to_end(&my_tetris0, my_tetris2);
	ft_tet_to_end(&my_tetris0, my_tetris3);
	ft_tet_to_end(&my_tetris0, my_tetris4);
	ft_tet_to_end(&my_tetris0, my_tetris5);
	ft_tet_to_end(&my_tetris0, my_tetris6);
	ft_tet_to_end(&my_tetris0, my_tetris7);
	//tet_ipos(my_tetris0, 4);
	t = my_tetris0;
	while (t)
	{
		tet_ipos(t, 4);
		t = t->next;
	}
	field_init(my_tetris0);
	/*
	while (my_tetris0)
	{
		ft_print_tet(my_tetris0, 4);
		my_tetris0 = my_tetris0->next;
	}
	*/
	return (0);
}
