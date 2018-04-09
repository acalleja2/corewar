/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:46:33 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/15 14:11:37 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	char	*cpy;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)&haystack[0]);
	while (haystack[i])
	{
		j = 0;
		cpy = (char *)&haystack[i];
		while (haystack[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return (cpy);
		}
		i++;
	}
	return (NULL);
}
