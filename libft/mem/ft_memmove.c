/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:27:35 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/10 18:48:35 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_cpy_forward(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char*)src;
	d = (unsigned char*)dest;
	while (n > 0)
	{
		*d = *s;
		++d;
		++s;
		--n;
	}
	return (dest);
}

static void	*ft_cpy_backward(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char*)src + n - 1;
	d = (unsigned char*)dest + n - 1;
	while (n > 0)
	{
		*d = *s;
		--d;
		--s;
		--n;
	}
	return (dest);
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	if (n >= 1024 * 1024 * 128)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	else if ((unsigned long)src > (unsigned long)dest)
		return (ft_cpy_forward(dest, src, n));
	else
		return (ft_cpy_backward(dest, src, n));
}
