/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:13:58 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/10 18:14:19 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	pos;

	if (!s)
		return (NULL);
	substring = (char*)ealloc((len + 1) * sizeof(char));
	pos = 0;
	while (pos < len)
	{
		substring[pos] = s[start + pos];
		pos++;
	}
	substring[pos] = '\0';
	return (substring);
}
