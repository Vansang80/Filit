/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:01:00 by trponess          #+#    #+#             */
/*   Updated: 2017/12/14 17:41:22 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/fillit.h"

char	**create_map(int size_map)
{
	char	**map;
	int		i;

	i = 0;
	map = (char**)malloc(sizeof(*map) * (size_map + 1));
	while (i < size_map)
	{
		map[i] = ft_strnew(size_map);
		ft_memset(map[i], '.', size_map);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	display_map(char **map)
{
	while (*map)
	{
		ft_putstr(*map);
		ft_putchar('\n');
		++map;
	}
}

int		size_map(int nbr_tetri)
{
	int		nb_diese;
	int		size;

	nb_diese = nbr_tetri * 4;
	while ((size = ft_sqrt(nb_diese)) == 0)
		++nb_diese;
	return (size);
}

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_piece(t_tetri **piece)
{
	int i;

	i = 0;
	while (piece[i])
		free(piece[i++]);
	free(piece);
}
