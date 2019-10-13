/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:09:50 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/12 23:33:32 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "fillit.h"

int		*get_x_coord(char *line)
{
	int		i;
	
	i = -1;
	while (++i < 4)
	{
		if (line[i] == '#')
			while
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
	t_list	*tetris;
	int		count;

	count = 0;
	tetris = NULL;
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		dimensions(line, count++);
	}
	return (0);
}

int				main(int ac, char **av)
{
	int		x[4] = {1, 2, 3, 4};
	int		y[4] = {3, 4, 5, 6};
	tetris	*my_tetris;

	if (ac == 2)
		ft_putnbr(get_tet(av[1]));
	else
		ft_putstr("./fillit [should be used this way]\n");
	ft_putstr("\nFirst print\n");
	my_tetris = tet_new(x, y);
	tet_print_coords(my_tetris);
	return (0);
}
