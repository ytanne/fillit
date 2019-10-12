/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:09:50 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/11 13:51:42 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

void	fillit(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

static void		tet_list(char *str)
{
	t_list	*tetrimon;

	tetrimon = ft_lstnew(str, 16);
}

static int		check_file(int counter, char *line)
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

static int		get_tet(char *str)
{
	int		fd;
	char	*line;
	int		rgnl;
	int		counter;

	fd = open(str, O_RDONLY);
	line = ft_strnew(16);
	counter = 0; 
	while ((rgnl = get_next_line(fd, &line)) > 0)
	{
		if (check_file(++counter, line) == -1)
			return (-1);
	}
	return (1);
}

int				main(int ac, char **av)
{
	if (ac == 2)
		ft_putnbr(get_tet(av[1]));
	else
		ft_putstr("./fillit [should be used this way]\n");
	return (0);
}
