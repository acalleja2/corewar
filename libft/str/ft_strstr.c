/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:17:38 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/06 17:17:39 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	npos;

	if (!ft_strlen(needle))
		return ((char*)haystack);
	while (*haystack)
	{
		npos = 0;
		while (needle[npos] && needle[npos] == *(haystack + npos))
			npos++;
		if (!needle[npos])
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
