/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:20:44 by florenzo          #+#    #+#             */
/*   Updated: 2018/02/07 15:44:17 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	pos;

	dup = (char*)ealloc(ft_strlen(s) + 1);
	pos = 0;
	while (s[pos])
	{
		dup[pos] = s[pos];
		pos++;
	}
	dup[pos] = '\0';
	return (dup);
}
