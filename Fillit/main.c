/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:56:21 by trponess          #+#    #+#             */
/*   Updated: 2017/12/14 17:32:28 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/fillit.h"

int		main(int argc, char **argv)
{
	char			buffer[546];
	int				nbr_tetri;
	char			**map;
	int				size;
	t_tetri			**stock_piece;

	if (!nb_argument(argc))
		return (0);
	nbr_tetri = read_file(argv[1], buffer);
	if (!check_buf(buffer, nbr_tetri) || !check_tetriminos(buffer, nbr_tetri))
		ft_error();
	stock_piece = create_piece(buffer, nbr_tetri);
	size = size_map(nbr_tetri);
	map = create_map(size);
	while (!find_solution(stock_piece, map, size, 0))
	{
		free_map(map);
		map = create_map(++size);
	}
	display_map(map);
	free_map(map);
	free_piece(stock_piece);
	return (0);
}
