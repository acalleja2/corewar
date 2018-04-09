/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:16:18 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/10 18:19:36 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	pos;
	char			*newstring;

	if (!s)
		return (NULL);
	newstring = (char*)ealloc((ft_strlen(s) + 1) * sizeof(char));
	if (!newstring)
		return (NULL);
	pos = 0;
	while (s[pos])
	{
		newstring[pos] = (f)(pos, s[pos]);
		pos++;
	}
	newstring[pos] = '\0';
	return (newstring);
}
