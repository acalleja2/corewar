/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 05:05:17 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/28 20:22:08 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		if (!(mem = (char *)malloc(sizeof(char) * (len1 + len2) + 1)))
			return (NULL);
		while (i < len1)
		{
			mem[i] = s1[i];
			i++;
		}
		while (j < len2)
			mem[i++] = s2[j++];
		mem[i] = '\0';
		return (mem);
	}
	return (NULL);
}
