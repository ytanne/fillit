/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:49:13 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/16 11:10:15 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

void	fill_with_dots(char ***str, int size)
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

void	print_it_already(char **res)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		ft_putstr(res[i]);
		ft_putchar('\n');
	}
}

int		backtrack(t_tetris *te, char ***res, int *i, char ch)
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
			return (0);
		if (backtrack(te, res, i, ch) == 1)
			return (1);
		(*res)[te->y[*i]][te->x[*i]] = '.';
	}
	return (0);
}

int		combinator(t_tetris *my_tetris)
{
	char		**res;
	int			i;
	t_tetris	*tut;
	int			x1[4] = {3, 3, 3, 3};
	int			y2[4] = {0, 1, 2, 3};

	tut = tet_new(x1, y2);
	i = -1;
	fill_with_dots(&res, 4);
	backtrack(my_tetris, &res, &i, 'A');
	ft_putstr("++++++++++\n");
	i = -1;
	backtrack(tut, &res, &i, 'B');
	return (1);
}

int		main(void)
{
	t_tetris	*my_tetris;
	int			x[4] = {2, 3, 1, 2};
	int			y[4] = {1, 1, 2, 2};

	my_tetris = tet_new(x, y);
	tet_ipos(&my_tetris);
	combinator(my_tetris);
	return (0);
}
