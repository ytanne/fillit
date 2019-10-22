/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:09:50 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/22 15:15:51 by mstupnik         ###   ########.fr       */
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

void			tet_init(char **tetstr, t_tetris **my_tetris, char letter)
{
	int			**coords;

	get_x_coord(*tetstr, &coords);
	if (!(*my_tetris))
		*my_tetris = ft_tetris_new(coords[0], coords[1], letter);
	else
		ft_tet_to_end(my_tetris, ft_tetris_new(coords[0], coords[1], letter));
	ft_strclr(*tetstr);
}

int				shape_filler(char *line, t_tetris **my_tetris, char letter, int fd)
{
	static char	*shape;
	char		nl;
	int			count;

	nl = '\n';
	count = -1;
	shape = ft_strnew(19);
	while (++count < 4)
	{
		if ((get_next_line(fd, &line) > 0))
		{
			ft_strcat(shape, line);
			ft_strncat(shape, &nl, 1);
			ft_strdel(&line);
		}
		else
			return (0);
	}
	if (!checker(shape))
		return (0);
	tet_init(&shape, my_tetris, letter++);
	ft_strdel(&shape);
	if ((get_next_line(fd, &line) > 0))
	{
		if ((ft_strchr(line, (int)"") == 0) 
			&& (shape_filler(line, my_tetris, letter, fd) == 1))
			return (1);
		else
			return (0);
	}
	return (1);
}

static int		get_tet(char *file_name, char **tetstr)
{
	int			fd;
	char		*line;
	char		letter;
	t_tetris	*my_tetris;

	letter = 'A';
	my_tetris = NULL;
	fd = open(file_name, O_RDONLY);
	if (!shape_filler(line, &my_tetris, letter, fd))
		return (0);
	field_init(my_tetris);
	return (1);
}

int				main(int ac, char **av)
{
	char	*tetstr;

	if (ac == 2)
	{
		if (!get_tet(av[1], &tetstr))
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fillit source_file.fillit\n");
	return (0);
}
