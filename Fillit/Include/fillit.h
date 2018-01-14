/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasnguye <pasnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:39:29 by pasnguye          #+#    #+#             */
/*   Updated: 2017/12/13 20:24:20 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "../Libft/libft.h"
# include <unistd.h>

typedef	struct	s_tetri
{
	int			x[4];
	int			y[4];
	char		letter;
}				t_tetri;

void			ft_error();
int				read_file(char *file_name, char *buffer);
int				nb_argument(int argc);
int				check_buf(char *buffer, int nbr_tetri);
int				check_tetriminos(char *buffer, int nbr_tetri);
t_tetri			**create_piece(char *buffer, int nbr_tetri);
int				size_map(int nbr_tetri);
char			**create_map(int size_map);
int				find_solution(t_tetri **piece, char **map, int size, int pos);
void			free_map(char **map);
void			display_map(char **map);
void			free_piece(t_tetri **piece);
int				check_link(char tab[4][4]);

#endif
