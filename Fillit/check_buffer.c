/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:23:21 by trponess          #+#    #+#             */
/*   Updated: 2017/12/13 20:41:29 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/fillit.h"

static int	count_replace(char *str, char find, char replace)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == find)
		{
			str[i] = replace;
			++count;
		}
		++i;
	}
	return (count);
}

int			check_buf(char *buffer, int nbr_tetri)
{
	char	*model;
	char	tetri[21];
	int		i;

	i = 0;
	model = "....\n....\n....\n....\n\n";
	while (i < nbr_tetri)
	{
		ft_strncpy(tetri, buffer + (i * 21), 21);
		if (count_replace(tetri, '#', '.') != 4)
			return (0);
		if (ft_strncmp(tetri, model, 21) != 0)
			return (0);
		++i;
	}
	return (1);
}
