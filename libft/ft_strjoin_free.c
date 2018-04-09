/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 00:57:32 by acalleja          #+#    #+#             */
/*   Updated: 2017/12/19 12:45:18 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int n)
{
	char	*mem;
	size_t	i;
	size_t	j;
	size_t	len[2];

	i = -1;
	j = 0;
	if (s1 && s2)
	{
		len[0] = ft_strlen(s1);
		len[1] = ft_strlen(s2);
		if (!(mem = (char *)malloc(sizeof(char) * (len[0] + len[1]) + 1)))
			return (NULL);
		while (++i < len[0])
			mem[i] = s1[i];
		while (j < len[1])
			mem[i++] = s2[j++];
		mem[i] = '\0';
		if ((n == 1 || n == 3) && s1)
			free(s1);
		if ((n == 2 || n == 3) && s2)
			free(s2);
		return (mem);
	}
	return (NULL);
}
