/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:24:35 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/10 18:52:45 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (*s1 == *s2 && n - 1 > 0)
	{
		if (!(*s1))
			return (0);
		++s1;
		++s2;
		--n;
	}
	return (*(const unsigned char*)s1 - *(const unsigned char*)s2);
}
