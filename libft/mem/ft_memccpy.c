/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:29:29 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/16 17:23:04 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			pos;
	unsigned char	stop;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	stop = (unsigned char)c;
	pos = 0;
	while (pos < n)
	{
		*d = *s;
		d++;
		if (*s == stop)
			return ((void*)d);
		s++;
		pos++;
	}
	return (NULL);
}
