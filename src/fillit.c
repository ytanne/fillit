/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:09:50 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/13 01:39:10 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "fillit.h"

void	get_x_coord(char *line)
{
	int		xy[2];
	int		j;
	int		k;
	int		coords[4][2];

	xy[0] = 0;
	xy[1] = 0;
	j = 0;
	k = -1;
	while (line[++k])
	{
		if (line[k] == '#')
		{
			coords[j][0] = xy[0];
			coords[j++][1] = xy[1];
		}
		if (line[k] == '\n')
		{
			xy[0] = 0;
			xy[1]++;
		}
		else
			xy[0]++;
	}
	k = -1;
	while (++k < 4)
	{
		ft_putstr("x: ");
		ft_putnbr(coords[k][0]);
		ft_putstr("; ");
		ft_putstr("y: ");
		ft_putnbr(coords[k][1]);
		ft_putchar('\n');
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

static int		get_tet(char *file_name)
{
	int		fd;
	char	*line;
	char	*tetstr;
	int		count;

	count = 0;
	fd = open(file_name, O_RDONLY);
	tetstr = ft_strnew(18);
	//ft_strclr(tetstr);
	while (get_next_line(fd, &line) > 0)
	{
		dimensions(line, count++);
		ft_strcat(tetstr, line);
		if (count < 4)
			tetstr[5*(count - 1) + 4] = '\n';
		else
		{
			tetstr[5*(count - 1) + 4] = '\0';
			count = 0;
		}
	}
	ft_putstr("Obtained tetstr is: \n");
	ft_putstr(tetstr);
	ft_putchar('\n');
	get_x_coord(tetstr);
	return (0);
}

int				main(int ac, char **av)
{
	int		x[4] = {1, 2, 3, 4};
	int		y[4] = {3, 4, 5, 6};
	tetris	*my_tetris;

	if (ac == 2)
		get_tet(av[1]);
	else
		ft_putstr("./fillit [should be used this way]\n");
	ft_putstr("\nFirst print\n");
	my_tetris = tet_new(x, y);
	tet_print_coords(my_tetris);
	return (0);
}
