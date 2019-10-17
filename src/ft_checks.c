/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:46:17 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/16 19:21:24 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "fillit.h"

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
	int hash_adj;
	
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
	if (shape_check(line) && basic_check(line))
		return (1);
	return (0);
}

static int		get_tet(char *file_name, char **tetstr)
{
	int			fd;
	char		*line;
	int			count;
	t_tetris	*my_tetris;

	count = -1;
	my_tetris = NULL;
	fd = open(file_name, O_RDONLY);
	*tetstr = ft_strnew(19);
	while (get_next_line(fd, &line) > 0)
	{
		++count;
		if (count < 3)
		{
			ft_strcat(*tetstr, line);
			(*tetstr)[5*count + 4] = '\n';
		}
		else if (count == 3)
		{
			ft_strcat(*tetstr, line);
			(*tetstr)[5*count + 4] = '\0';
			ft_putstr("Checker result: ");
			ft_putnbr(checker(*tetstr));
			ft_putchar('\n');
			ft_strclr(*tetstr);
		}
		else if (count == 4 && ft_strcmp(line, "") == 0)
			count = -1;
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
