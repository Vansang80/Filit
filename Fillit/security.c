/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:52:10 by trponess          #+#    #+#             */
/*   Updated: 2017/12/15 14:21:23 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

int		nb_argument(int argc)
{
	if (argc == 1 || argc > 2)
	{
		ft_putstr_fd("usage: ./fillit file\n", 2);
		return (0);
	}
	return (1);
}

int		read_file(char *file_name, char *buffer)
{
	int		fd;
	int		r_bytes;
	int		nbr_tetri;

	if ((fd = open(file_name, O_RDONLY)) <= 0)
		ft_error();
	if ((((r_bytes = read(fd, buffer, 546)) + 1) / 21) > 26)
		ft_error();
	if ((r_bytes + 1) % 21 != 0)
		ft_error();
	if ((nbr_tetri = (r_bytes + 1) / 21) == 0)
		ft_error();
	buffer[r_bytes] = '\n';
	close(fd);
	return (nbr_tetri);
}
