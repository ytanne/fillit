/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:02:00 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/12 23:22:25 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	comp
{
	int			x[4];
	int			y[4];
	struct comp	*next;
}				tetris;

int				ft_file_check(int counter, char *line);
tetris			*tet_new(int *x, int *y);
void			tet_add_to_end(tetris **my_tetris, tetris *part);
void			tet_print_coords(tetris *my_tetris);

#endif
