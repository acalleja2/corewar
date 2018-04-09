/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:16:05 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/10 18:55:52 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	pos;

	pos = 0;
	while (s[pos])
		pos++;
	--pos;
	if (c == 0)
		return ((char*)&s[pos + 1]);
	while (pos + 1)
	{
		if (s[pos] == c)
			return ((char*)&s[pos]);
		pos--;
	}
	return (NULL);
}
