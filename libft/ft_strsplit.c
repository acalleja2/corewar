/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 06:43:04 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/10 06:41:17 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_words(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	bol;

	i = 0;
	count = 0;
	while (s[i])
	{
		bol = 0;
		while (s[i] != c && s[i])
		{
			if (bol == 0)
			{
				bol = 1;
				count++;
			}
			i++;
		}
		if (s[i])
			i++;
	}
	return (count);
}

static void		ft_cpy(char const *s, char c, char **tab)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] != c && s[i])
		{
			tab[j][k] = s[i];
			k++;
			i++;
		}
		if (k > 0)
		{
			tab[j][k] = '\0';
			j++;
		}
		if (s[i] && s[i] == c)
			i++;
	}
}

static char		**ft_norm(char const *s, char c, size_t i, size_t j)
{
	size_t	k;
	size_t	words;
	char	**tab;

	words = ft_words(s, c);
	if (!(tab = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (s[i])
	{
		k = 0;
		while (s[i] != c && s[i])
		{
			k++;
			i++;
		}
		if (k > 0)
			if (!(tab[j++] = (char *)malloc(sizeof(char) * k + 1)))
				return (NULL);
		if (s[i] && s[i] == c)
			i++;
	}
	ft_cpy(s, c, tab);
	tab[words] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	words;
	char	**tab;

	if (s)
	{
		words = ft_words(s, c);
		if (!(tab = ft_norm(s, c, 0, 0)))
			return (NULL);
		ft_cpy(s, c, tab);
		tab[words] = 0;
		return (tab);
	}
	return (NULL);
}
