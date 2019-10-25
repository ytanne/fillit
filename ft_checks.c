/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:46:17 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/24 20:17:36 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int		basic_check(char *line)
{
	int i;
	int hash_count;
	int	dot_count;

	if (!line)
		return (0);
	i = -1;
	hash_count = 0;
	dot_count = 0;
	while (line[++i])
	{
		if (line[i] == '#')
			hash_count++;
		else if (line[i] == '.')
			dot_count++;
		else if (line[i] == '\n')
			continue ;
		else
			return (0);
	}
	if (hash_count != 4 || dot_count != 12)
		return (0);
	return (1);
}

static int		adj_check(int i, char *line)
{
	int	hash_adj;

	hash_adj = 0;
	if (line[i] == '#')
	{
		if (line[i + 1] == '#')
			hash_adj++;
		if (line[i - 1] == '#')
			hash_adj++;
		if (line[i + 5] == '#' && (i + 5 <= 19))
			hash_adj++;
		if (line[i - 5] == '#' && (i - 5 >= 0))
			hash_adj++;
		if (hash_adj == 0)
			return (0);
	}
	return (hash_adj);
}

static int		shape_check(char *line)
{
	int sum;
	int i;

	i = -1;
	sum = 0;
	while (line[++i])
		if (line[i] == '#')
			sum += adj_check(i, line);
	if (sum < 6)
		return (0);
	return (1);
}

int				checker(char *line)
{
	if (basic_check(line) && shape_check(line))
		return (1);
	return (0);
}
