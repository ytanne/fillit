/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:09:50 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/14 02:28:42 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "fillit.h"

void	new_int_arr(int ***coords)
{
	(*coords) = ft_memalloc(2);
	(*coords)[0] = ft_memalloc(4);
	(*coords)[1] = ft_memalloc(4);
}

void	get_x_coord(char *line, int ***coords)
{
	int		xy[2];
	int		j;
	int		k;

	xy[0] = 0;
	xy[1] = 0;
	j = 0;
	k = -1;
	new_int_arr(coords);
	while (line[++k] && *coords)
	{
		if (line[k] == '#')
		{
			(*coords)[0][j] = xy[0];
			(*coords)[1][j++] = xy[1];
		}
		if (line[k] == '\n')
		{
			xy[0] = 0;
			xy[1]++;
		}
		else
			xy[0]++;
	}
}

void	dimensions(char	*line, int counter)
{
	static int	max_x = 0;
	static int	max_y = 0;
	static int	min_x = 4;
	static int	min_y = 4;
	int			i;

	i = -1;
	while (line[++i])
		if (line[i] == '#')
		{
			if (i > max_x)
				max_x = i;
			if (i < min_x)
				min_x = i;
			if (counter > max_y)
				max_y = counter;
			if (counter < min_y)
				min_y = counter;
		}
}

void			another_function(char **tetstr)
{
	int		**coords;
	tetris	*my_tetris;

	my_tetris = NULL;
	get_x_coord(*tetstr, &coords);
	my_tetris = tet_new(coords[0], coords[1]);
	tet_print_coords(my_tetris);
}

static int		get_tet(char *file_name, char **tetstr)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(file_name, O_RDONLY);
	*tetstr = ft_strnew(18);
	while (get_next_line(fd, &line) > 0)
	{
		dimensions(line, count++);
		ft_strcat(*tetstr, line);
		if (count < 4)
			(*tetstr)[5*(count - 1) + 4] = '\n';
		else
		{
			(*tetstr)[5*(count - 1) + 4] = '\0';
			count = 0;
			another_function(tetstr);
		}
	}
	return (0);
}

int				main(int ac, char **av)
{
	char	*tetstr;

	if (ac == 2)
		ft_putnbr(get_tet(av[1], &tetstr));
	else
		ft_putstr("./fillit [should be used this way]\n");
	return (0);
}
