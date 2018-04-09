/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:29:07 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/09 15:57:30 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			pos;

	pos = 0;
	ptr = (unsigned char*)s;
	while (pos < n)
	{
		if (*ptr == (unsigned char)c)
			return ((void*)ptr);
		++ptr;
		++pos;
	}
	return (NULL);
}
