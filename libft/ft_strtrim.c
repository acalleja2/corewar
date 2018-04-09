/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 06:05:36 by acalleja          #+#    #+#             */
/*   Updated: 2017/12/18 11:20:15 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_trim(char const *s, int i, int k, int j)
{
	char *mem;

	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while ((s[j - 1] == ' ' || s[j - 1] == '\t' || s[j - 1] == '\n') && j > 0)
		j--;
	if (i >= j)
	{
		if (!(mem = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		mem[0] = '\0';
		return (mem);
	}
	if (!(mem = (char *)malloc(sizeof(char) * (j - i + 1))))
		return (NULL);
	while (i < j)
		mem[k++] = s[i++];
	mem[k] = '\0';
	return (mem);
}

char			*ft_strtrim(char const *s)
{
	int		j;
	char	*mem;

	if (s)
	{
		j = ft_strlen(s);
		mem = ft_trim(s, 0, 0, j);
		return (mem);
	}
	return (NULL);
}
