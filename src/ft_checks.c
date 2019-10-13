/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:46:17 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/12 15:03:13 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		ft_file_check(int counter, char *line)
{
	if (counter == 5)
	{
		counter = 0;
		if (ft_strcmp(line, "") != 0)
			return (-1);
	}
	else if (ft_strlen(line) != 4)
		return (-1);
	return (1);
}
