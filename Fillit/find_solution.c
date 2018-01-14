/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 20:57:02 by trponess          #+#    #+#             */
/*   Updated: 2017/12/14 17:40:08 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/fillit.h"

int		try_position(t_tetri *piece, char **map, int size, int pos)
{
	int		row;
	int		col;
	int		i;
	int		x;
	int		y;

	row = pos / size;
	col = pos % size;
	i = 0;
	while (++i < 4)
	{
		y = row + piece->y[i];
		x = col + piece->x[i];
		if (x < 0 || x >= size || y < 0 || y >= size || map[y][x] != '.')
			return (0);
	}
	i = -1;
	while (++i < 4)
	{
		y = row + piece->y[i];
		x = col + piece->x[i];
		map[y][x] = piece->letter;
	}
	return (1);
}

int		place_piece(t_tetri *piece, char **map, int size, int pos)
{
	int		row;
	int		col;

	row = pos / size;
	col = pos % size;
	while (row < size)
	{
		while (col < size)
		{
			if (map[row][col] == '.')
			{
				if (try_position(piece, map, size, pos))
					return (pos);
			}
			pos++;
			col++;
		}
		col = 0;
		row++;
	}
	return (-1);
}

void	remove_piece(char **map, t_tetri *piece, int pos, int size)
{
	int i;
	int	x;
	int y;

	i = 0;
	while (i < 4)
	{
		x = pos % size + piece->x[i];
		y = pos / size + piece->y[i];
		map[y][x] = '.';
		++i;
	}
}

int		find_solution(t_tetri **stock_piece, char **map, int size, int pos)
{
	if (*stock_piece == NULL)
		return (1);
	if ((pos = place_piece(*stock_piece, map, size, pos)) < 0)
		return (0);
	if (find_solution(stock_piece + 1, map, size, 0))
		return (1);
	while (pos < size * size)
	{
		remove_piece(map, *stock_piece, pos, size);
		if ((pos = place_piece(*stock_piece, map, size, ++pos)) < 0)
			return (0);
		if (find_solution(stock_piece + 1, map, size, 0))
			return (1);
	}
	return (0);
}
