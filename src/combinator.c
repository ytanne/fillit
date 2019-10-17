/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:49:13 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/16 16:24:58 by yorazaye         ###   ########.fr       */
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

int		iterate_pos(t_tetris **te, char ***res, char ch)
{
	int		i;
	int		counter;

	i = -1;
	if (backtrack(*te, res, &i, ch))
		return (1);
	else
	{
		if (tet_move_hor(te, "right") == 1)
		{
			counter++;
			iterate_pos(te, res, ch);
		}
		else
		{
			while (counter-- > 0)
				tet_move_hor(te, "left");
			if (tet_move_ver(te, "down") == 1)
				iterate_pos(te, res, ch);
		}
	}
	return (0);
}

int		combinator(t_tetris *my_tetris)
{
	char		**res;
	int			i;
	t_tetris	*tut;
	t_tetris	*tut2;
	//int			x1[4] = {0, 0, 0, 0};
	//int			y2[4] = {0, 1, 2, 3};
	int			x1[4] = {0, 1, 2, 3};
	int			y2[4] = {0, 0, 0, 0};

	tut = tet_new(x1, y2);
	tut2 = tet_new(x1, y2);
	i = -1;
	fill_with_dots(&res, 4);
	backtrack(my_tetris, &res, &i, 'A');
	ft_putstr("++++++++++\n");
	/*i = -1;
	backtrack(tut, &res, &i, 'B');
	i = -1;
	while (++i < 4)
	{
		ft_putstr(res[i]);
		ft_putchar('\n');
	}*/
	iterate_pos(&tut, &res, 'B');
	ft_putstr("++++++++++\n");
	iterate_pos(&tut2, &res, 'C');
	ft_putstr("++++++++++\n");
	iterate_pos(&tut2, &res, 'D');
	i = -1;
	while (++i < 4)
	{
		ft_putstr(res[i]);
		ft_putchar('\n');
	}
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
