/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:27:11 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/06 17:27:12 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		pos;

	pos = 0;
	while (dest[pos])
		pos++;
	while (*src)
	{
		dest[pos++] = *src;
		++src;
	}
	dest[pos] = '\0';
	return (dest);
}
