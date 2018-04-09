/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:11:45 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/09 21:01:22 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	pos;
	size_t	i;

	if (!(*little))
		return ((char*)big);
	pos = 0;
	while (big[pos] && pos < len)
	{
		i = 0;
		while (big[pos + i] == little[i] && little[i] && i < len - pos)
			++i;
		if (!(little[i]))
			return ((char*)&(big[pos]));
		++pos;
	}
	return (NULL);
}
