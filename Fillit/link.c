/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:48:27 by trponess          #+#    #+#             */
/*   Updated: 2017/12/13 20:24:17 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/fillit.h"

static int	count_link(char tab[4][4], int x, int y)
{
	int		count_link;

	count_link = 0;
	if (tab[y][x - 1] == '#' && x != 0)
		count_link++;
	if (tab[y][x + 1] == '#' && x != 3)
		count_link++;
	if (tab[y - 1][x] == '#' && y != 0)
		count_link++;
	if (tab[y + 1][x] == '#' && y != 3)
		count_link++;
	return (count_link);
}

int			check_link(char tab[4][4])
{
	int		y;
	int		x;
	int		link;

	y = 0;
	link = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tab[y][x] == '#')
				link += count_link(tab, x, y);
			++x;
		}
		++y;
	}
	return (link);
}
