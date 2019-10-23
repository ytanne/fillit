/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leakage_deal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:19:43 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/22 18:28:58 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	delete_tet(t_tetris **t)
{
	t_tetris	*tmp;

	while (*t)
	{
		tmp = (*t)->next;
		free(*t);
		*t = tmp;
	}
	*t = NULL;
}
