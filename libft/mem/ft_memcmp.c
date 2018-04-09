/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:28:50 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/06 17:31:37 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			pos;

	ptr1 = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	pos = 0;
	while (pos < n)
	{
		if (*ptr1 != *ptr2)
			return ((int)*ptr1 - (int)*ptr2);
		ptr1++;
		ptr2++;
		pos++;
	}
	return (0);
}
