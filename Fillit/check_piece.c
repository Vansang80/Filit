/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:23:40 by trponess          #+#    #+#             */
/*   Updated: 2017/12/14 17:33:26 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/fillit.h"

static void		fill_tab(char tab[4][4], char *tetri_one_by_one)
{
	int		row;
	int		col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			tab[row][col] = tetri_one_by_one[row * 5 + col];
			++col;
		}
		++row;
	}
}

int				check_tetriminos(char *buffer, int nbr_tetri)
{
	char	tab[4][4];
	int		i;

	i = 0;
	while (i < nbr_tetri)
	{
		fill_tab(tab, buffer + (i * 21));
		if (check_link(tab) < 6)
			return (0);
		++i;
	}
	return (1);
}

static void		calcul_offset(char tab[4][4], int *i, int *y_off, int *x_off)
{
	while (*i < 16)
	{
		if (tab[*i / 4][*i % 4] == '#')
		{
			*y_off = *i / 4;
			*x_off = *i % 4;
			break ;
		}
		(*i)++;
	}
}

static void		convert_coordonnes(char tab[4][4], t_tetri *piece)
{
	int		i;
	int		p;
	int		y_offset;
	int		x_offset;

	i = 0;
	p = 0;
	calcul_offset(tab, &i, &y_offset, &x_offset);
	while (i < 16)
	{
		if (tab[i / 4][i % 4] == '#')
		{
			piece->y[p] = i / 4 - y_offset;
			piece->x[p] = i % 4 - x_offset;
			p++;
		}
		i++;
	}
}

t_tetri			**create_piece(char *buffer, int nbr_tetri)
{
	t_tetri		**piece;
	char		tab[4][4];
	int			i;

	i = 0;
	piece = (t_tetri**)malloc(sizeof(t_tetri*) * (nbr_tetri + 1));
	if (!piece)
		return (0);
	while (i < nbr_tetri)
	{
		piece[i] = (t_tetri*)malloc(sizeof(t_tetri));
		fill_tab(tab, buffer + (i * 21));
		convert_coordonnes(tab, piece[i]);
		piece[i]->letter = 'A' + i;
		i++;
	}
	piece[i] = NULL;
	return (piece);
}
