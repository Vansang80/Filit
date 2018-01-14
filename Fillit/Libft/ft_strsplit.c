/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasnguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 21:53:10 by pasnguye          #+#    #+#             */
/*   Updated: 2017/11/22 05:33:13 by pasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**tab(char const *s, char c, int nb_words, int max_len_words)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	str = (char**)malloc(sizeof(*str) * nb_words + 1);
	if (!str)
		return (NULL);
	while (j < nb_words && s[i])
	{
		k = 0;
		str[j] = (char*)malloc(sizeof(**str) * max_len_words + 1);
		if (!str)
			return (NULL);
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			str[j][k++] = s[i++];
		str[j][k] = '\0';
		j++;
	}
	str[j] = 0;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int		nb_words;
	int		len_words;
	int		max_len_words;
	int		i;

	nb_words = 0;
	max_len_words = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i++])
	{
		len_words = 0;
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			nb_words++;
			while (s[i] != c && s[i++])
				len_words++;
			if (len_words > max_len_words)
				max_len_words = len_words;
		}
	}
	return (tab(s, c, nb_words, max_len_words));
}
