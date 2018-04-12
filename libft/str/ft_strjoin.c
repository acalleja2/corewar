/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:23:12 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/10 18:13:38 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	char	*cpy;

	if (!s1 || !s2)
		return (NULL);
	nstr = (char*)ealloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	cpy = nstr;
	while (*s1)
	{
		*nstr = *s1;
		++nstr;
		++s1;
	}
	while (*s2)
	{
		*nstr = *s2;
		++nstr;
		++s2;
	}
	*nstr = '\0';
	return (cpy);
}
