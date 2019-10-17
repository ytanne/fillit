/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:09:50 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/16 18:14:37 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "fillit.h"

static void		new_int_arr(int ***coords)
{
	(*coords) = ft_memalloc(2);
	(*coords)[0] = ft_memalloc(4);
	(*coords)[1] = ft_memalloc(4);
}

static void		get_x_coord(char *line, int ***coords)
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

static void		dimensions(char	*line, int counter)
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

void			tet_init(char **tetstr, t_tetris **my_tetris)
{
	int			**coords;

	get_x_coord(*tetstr, &coords);
	if (!(*my_tetris))
		*my_tetris = tet_new(coords[0], coords[1]);
	else
		tet_add_to_end(my_tetris, tet_new(coords[0], coords[1]));
	ft_strclr(*tetstr);
}

static int		get_tet(char *file_name, char **tetstr)
{
	int			fd;
	char		*line;
	int			count;
	t_tetris	*my_tetris;

	count = 0;
	my_tetris = NULL;
	fd = open(file_name, O_RDONLY);
	*tetstr = ft_strnew(19);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strcmp(line, "") == 0)
			continue ;
		dimensions(line, count++);
		ft_strcat(*tetstr, line);
		if (count < 4)
			(*tetstr)[5*(count - 1) + 4] = '\n';
		else
		{
			(*tetstr)[5*(count - 1) + 4] = '\0';
			count = 0;
			tet_init(tetstr, &my_tetris);
		}
	}
	tet_print_coords(my_tetris);
	ft_putstr("====================\n");
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
