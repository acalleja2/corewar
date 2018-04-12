/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 17:38:27 by florenzo          #+#    #+#             */
/*   Updated: 2018/03/10 17:38:27 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Join n chaines de caracteres
** Exemple :
** char *new = str_join_n(3, "Hello ", "World ", "!");
*/

static void		va_fill_tab(va_list ptrs, char **tab, int n)
{
	int			pos;

	pos = 0;
	while (pos < n)
	{
		tab[pos] = va_arg(ptrs, char*);
		pos += 1;
	}
}

static size_t	total_len(char **tab, int n)
{
	int			pos;
	size_t		len;

	pos = 0;
	len = 0;
	while (pos < n)
	{
		if (NULL != tab[pos])
			len += ft_strlen(tab[pos]);
		pos += 1;
	}
	return (len);
}

char			*str_join_n(int n, ...)
{
	char		**tab;
	va_list		ptrs;
	int			pos;
	char		*res;

	tab = ealloc(n * sizeof(char*));
	va_start(ptrs, n);
	va_fill_tab(ptrs, tab, n);
	va_end(ptrs);
	res = ealloc(total_len(tab, n) + 1);
	pos = 0;
	res[0] = '\0';
	while (pos < n)
	{
		if (NULL != tab[pos])
			ft_strcat(res, tab[pos]);
		pos += 1;
	}
	free(tab);
	return (res);
}
