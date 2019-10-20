/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:37:30 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/20 14:47:05 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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

void		delete_field(char	***field, int n)
{
	int		i;
	char	*ptr;

	i = -1;
	while (++i < n)
	{
		ft_strdel(&(*field)[i]);
	}
	*field = NULL;
}
