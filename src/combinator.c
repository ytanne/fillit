/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:49:13 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/17 18:10:13 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

/*
** Function that fills the box with dots
*/

static void	fill_with_dots(char ***str, int size)
{
	int		i;
	int		l;

	i = -1;
	*str = (char **)malloc(sizeof(char *) * size + 1);
	while (++i < size)
	{
		(*str)[i] = ft_strnew(size);
		ft_memset((*str)[i], '.', size);
		(*str)[i][size] = '\0';
	}
	(*str)[size] = NULL;
}

/*
** Function that can be deleted or removied
*/

static void	print_it_already(char **res)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		ft_putstr(res[i]);
		ft_putchar('\n');
	}
	ft_putstr("==================\n");
}

/*
** This function tries to place the blocks of a tetrimino
*/

static int	backtrack(t_tetris *te, char ***res, int *i, char ch)
{
	if (++(*i) == 4)
	{
		print_it_already(*res);
		return (1);
	}
	else
	{
		if ((*res)[te->y[*i]][te->x[*i]] == '.')
			(*res)[te->y[*i]][te->x[*i]] = ch;
		else
		{
			(*i)--;
			return (0);
		}
		if (backtrack(te, res, i, ch) == 1)
			return (1);
		(*res)[te->y[*i]][te->x[*i]] = '.';
	}
	return (0);
}


int			move_2nl(t_tetris **te, char ***res, char ch, int (*f)(t_tetris **, char ***, char))
{
	if (tet_move_hor(te, "right") == 1)
	{
		if (f(te, res, ch))
			return (1);
	}
	else
	{
		while (tet_move_hor(te, "left") > 0)
			;
		if (tet_move_ver(te, "down") == 1)
			if (f(te, res, ch))
				return (1);
	}
	return (0);
}

/*
** This function iterates the position of tetriminos
*/

static int	iterate_pos(t_tetris **te, char ***res, char ch)
{
	int		i;

	i = -1;
	if (backtrack(*te, res, &i, ch))
		return (1);
	else
	{
		/*
		if (tet_move_hor(te, "right") == 1)
		{
			if (iterate_pos(te, res, ch))
				return (1);
		}
		else
		{
			while (tet_move_hor(te, "left") > 0)
				;
			if (tet_move_ver(te, "down") == 1)
				if (iterate_pos(te, res, ch))
					return (1);
		}
		*/
		if (move_2nl(te, res, ch, iterate_pos))
			return (1);
	}
	ft_putstr("Oh my zsh\n");
	return (0);
}

/*
** Iterate the tetrimino so it will change the place
*/

static int	tet_order(t_tetris **te, char ***res, char ch)
{
	t_tetris	*ptr;

	if (iterate_pos(te, res, ch++))
	{
		ptr = *te;
		if ((*te)->next)
		{
			if (tet_order(&(*te)->next, res, ch))
				return (1);
		}
		else
			return (1);
	}
	else
	{
		/*
		if (tet_move_hor(&ptr, "right") > 0)
		{
			if (tet_order(&ptr, res, ch))
				return (1);
		}
		else
		{
			while (tet_move_hor(&ptr, "left") > 0)
				;
			if (tet_move_ver(&ptr, "down") > 0)
				if (tet_order(&ptr, res, ch))
					return (1);
		}
		^ working
		======================================
		if (tet_move_hor(te, "right") > 0)
		{
			if (tet_order(te, res, ch))
				return (1);
		}
		else
		{
			while (tet_move_hor(te, "left") > 0)
				;
			if (tet_move_ver(te, "down") > 0)
				if (tet_order(te, res, ch))
					return (1);
		}
	}*/
	/*
	else
	{
		if (tet_move_hor(te, "right") == 1)
		{
			if (tet_order(te, res, ch))
				return (1);
		}
		else
		{
			while (tet_move_hor(te, "left") > 0)
				;
			if (tet_move_ver(te, "down") == 1)
				if (tet_order(te, res, ch))
					return (1);
		}
		*/
		if (move_2nl(&ptr, res, ch, tet_order))
			return (1);
	}
	ft_putstr("Oh shit! Here we go again\n");
	return (0);
}

/*
** Need to change this function
*/

int		combinator(t_tetris *my_tetris)
{
	char		**res;
	int			i;
	char		ch;

	i = -1;
	ch = 'A';
	fill_with_dots(&res, 4);
	tet_order(&my_tetris, &res, ch);
	/*
	i = -1;
	while (++i < 4)
	{
		ft_putstr(res[i]);
		ft_putchar('\n');
	}
	*/
	return (1);
}

int		main(void)
{
	t_tetris	*my_tetris;
	int			x[4] = {2, 3, 1, 2};
	int			y[4] = {1, 1, 2, 2};
	int			x1[4] = {0, 1, 2, 3};
	int			y1[4] = {0, 0, 0, 0};
	int			x2[4] = {0, 0, 0, 0};
	int			y2[4] = {0, 1, 2, 3};

	my_tetris = tet_new(x, y);
	tet_ipos(&my_tetris);
	tet_add_to_end(&my_tetris, tet_new(x1, y1));
	tet_add_to_end(&my_tetris, tet_new(x2, y2));
	combinator(my_tetris);
	return (0);
}
