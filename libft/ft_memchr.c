/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:10:12 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/14 15:03:21 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpy;

	i = 0;
	while (i < n)
	{
		cpy = (unsigned char *)&s[i];
		if (cpy[0] == (unsigned char)c)
			return (cpy);
		i++;
	}
	return (NULL);
}
