/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leakage_deal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:19:43 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/24 21:30:15 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>

void	delete_tet(t_tetris **t)
{
	t_tetris	*tmp;

	while (*t)
	{
		ft_memdel((void **)&(*t)->x);
		ft_memdel((void **)&(*t)->y);
		(*t)->prev = NULL;
		(*t)->letter = (char)NULL;
		tmp = (*t);
		*t = (*t)->next;
		tmp->next = NULL;
		ft_memdel((void **)&tmp);
	}
	t = NULL;
}

void	ft_intdel(int ***coords)
{
	ft_memdel((void **)(&(*coords)[0]));
	ft_memdel((void **)(&(*coords)[1]));
	ft_memdel((void **)(*coords));
}

void	delete_field(char ***field, int n)
{
	int		i;

	i = -1;
	while (++i < n)
	{
		ft_memdel((void **)&(*field)[i]);
	}
	free(*field);
	field = NULL;
}
