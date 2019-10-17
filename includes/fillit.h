/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:02:00 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/16 18:04:31 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_tetris
{
	struct s_tetris	*next;
	int				x[4];
	int				y[4];
}				t_tetris;

int				ft_file_check(int counter, char *line);
t_tetris		*tet_new(int *x, int *y);
void			tet_add_to_end(t_tetris **my_tetris, t_tetris *part);
void			tet_print_coords(t_tetris *my_tetris);
void			tet_print_gui(t_tetris *s_t, int dimensions, char cc);
void			tet_ipos(t_tetris **my_tetris);
int				tet_move_hor(t_tetris **my_tetris, char *lefrig);
int				tet_move_ver(t_tetris **my_tetris, char *updo);

#endif
