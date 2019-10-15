/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:46:17 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/14 21:27:39 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		basic_check(char *line)				//checks for required amount of dots and hashes
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

int		shape_check(int *line)					//counts amount of adjacent blocks
{
	int sum;
	int hash_adj;
	int i;

	i = -1;
	sum = 0;
	while(line[++i])							//function is too big
	{
		hash_adj = 0;
		if (line[i] == '#')
		{
			if (line[i + 1] == '#')
				hash_adj++;
			if (line[i - 1] == '#')
				hash_adj++;
			if (line[i + 5] == '#') 			//check for segfault
				hash_adj++;
			if (line[i - 5] == '#')
				hash_adj++;
			if (hash_adj == 0)
				return (0);
			else
				sum += hash_adj;
		}
	}
	if (sum < 6)
		return (0);
	return (1);
}
