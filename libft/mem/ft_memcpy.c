/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:28:58 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/06 17:28:59 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			pos;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	pos = 0;
	while (pos < n)
	{
		*d = *s;
		d++;
		s++;
		pos++;
	}
	return (dest);
}
