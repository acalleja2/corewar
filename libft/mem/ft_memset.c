/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:28:19 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/09 15:32:38 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			pos;

	ptr = (unsigned char*)s;
	pos = 0;
	while (pos < n)
	{
		ptr[pos] = (unsigned char)c;
		pos += 1;
	}
	return (s);
}
