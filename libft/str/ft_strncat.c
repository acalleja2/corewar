/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:14:38 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/06 17:14:40 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	pos;
	size_t	len;

	pos = 0;
	while (dest[pos])
		pos++;
	len = 0;
	while (src[len] && len < n)
	{
		dest[pos] = src[len];
		len++;
		pos++;
	}
	dest[pos] = '\0';
	return (dest);
}
