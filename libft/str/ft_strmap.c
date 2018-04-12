/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:16:46 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/10 19:00:12 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstring;
	char	*cpy;

	if (!s)
		return (NULL);
	newstring = (char*)ealloc((ft_strlen(s) + 1) * sizeof(char));
	cpy = newstring;
	while (*s)
	{
		*newstring = (f)(*s);
		newstring++;
		s++;
	}
	*newstring = '\0';
	return (cpy);
}
