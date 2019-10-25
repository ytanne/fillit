/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:09:50 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/24 21:37:52 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "fillit.h"

static void		tet_init(char **tetstr, t_tetris **my_tetris, char letter)
{
	int			**coords;

	get_x_coord(*tetstr, &coords);
	if (!(*my_tetris))
		*my_tetris = ft_tetris_new(coords[0], coords[1], letter);
	else
		ft_tet_to_end(my_tetris, ft_tetris_new(coords[0], coords[1], letter));
	ft_intdel(&coords);
	free(coords);
	ft_strclr(*tetstr);
}

static int		create_shape(int fd, char **line, char **shape)
{
	int		count;
	char	nl;

	count = -1;
	nl = '\n';
	while (++count < 4)
	{
		if ((get_next_line(fd, line) > 0))
		{
			ft_strcat(*shape, *line);
			ft_strncat(*shape, &nl, 1);
			ft_strdel(line);
		}
		else
			return (0);
	}
	ft_strdel(line);
	return (1);
}

int				shape_filler(char *line, t_tetris **my_tetris,
		char letter, int fd)
{
	char		*shape;
	char		nl;
	int			count;

	nl = '\n';
	count = -1;
	shape = ft_strnew(19);
	create_shape(fd, &line, &shape);
	if (!checker(shape))
		return (0);
	tet_init(&shape, my_tetris, letter++);
	ft_strdel(&shape);
	if ((get_next_line(fd, &line) > 0))
	{
		if ((ft_strchr(line, (int)"") == 0)
			&& (shape_filler(line, my_tetris, letter, fd) == 1))
		{
			ft_strdel(&line);
			return (1);
		}
		else
			return (0);
	}
	return (1);
}

static int		get_tet(char *file_name)
{
	int			fd;
	char		*line;
	char		letter;
	t_tetris	*my_tetris;
	int			size;

	letter = 'A';
	my_tetris = NULL;
	fd = open(file_name, O_RDONLY);
	if (!shape_filler(line, &my_tetris, letter, fd))
		return (0);
	field_init(my_tetris);
	delete_tet(&my_tetris);
	free(my_tetris);
	my_tetris = NULL;
	return (1);
}

int				main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!get_tet(av[1]))
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fillit source_file.fillit\n");
	return (0);
}
