/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:29:48 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/10 21:04:09 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	w_len(const char *s, int p, char sep)
{
	int		c;

	c = 0;
	while (s[p] && s[p] != sep)
	{
		c++;
		p++;
	}
	c++;
	return (c);
}

static int	t_words(const char *str, char sep)
{
	int		pos;
	int		c;

	pos = 0;
	c = 0;
	while (str[pos])
	{
		if (str[pos] != sep)
		{
			c++;
			while (str[pos] && str[pos] != sep)
				pos++;
		}
		while (str[pos] == sep)
			pos++;
	}
	return (c + 1);
}

static char	**ft_norm(char **tab, int lin)
{
	tab[lin + 1] = NULL;
	return (tab);
}

char		**ft_strsplit(const char *str, char sep)
{
	char	**tab;
	int		p;
	int		lin;
	int		col;

	p = 0;
	lin = -1;
	if (!str || !(tab = (char**)ealloc(sizeof(char*) * t_words(str, sep))))
		return (NULL);
	while (str[p])
	{
		if (str[p] != sep)
		{
			lin++;
			col = 0;
			tab[lin] = (char*)ealloc(sizeof(char) * w_len(str, p, sep));
			while (str[p] && str[p] != sep)
				tab[lin][col++] = str[p++];
			tab[lin][col] = '\0';
		}
		while (str[p] && str[p] == sep)
			p++;
	}
	return (ft_norm(tab, lin));
}
