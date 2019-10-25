/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:37:21 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/24 21:04:28 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_tetris
{
	int				*x;
	int				*y;
	char			letter;
	struct s_tetris	*next;
	struct s_tetris	*prev;
}				t_tetris;

t_tetris		*ft_tetris_new(int *x, int *y, char letter);
void			ft_tet_to_end(t_tetris **my_tetris, t_tetris *part);
void			ft_print_tet(t_tetris *s_t, int dimensions);
void			tet_ipos(t_tetris *my_tetris, int size);
int				tet_move_hor(t_tetris **my_tetris, char *lefrig, int size);
int				tet_move_ver(t_tetris **my_tetris, char *updown, int size);
char			**create_field(int n);
void			print_field(char **field, int n);
void			delete_field(char ***field, int n);
int				checker(char *line);
void			field_init(t_tetris *t);
void			new_int_arr(int ***coords);
void			get_x_coord(char *line, int ***coords);
int				tet_getmax(t_tetris *my_tetris);
void			delete_tet(t_tetris **tetris);
void			ft_intdel(int ***coords);
int				init_size_pose(t_tetris **t);

#endif
