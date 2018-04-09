/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 02:44:08 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/15 14:23:09 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*mem;

	if (s && f)
	{
		if (!(mem = ft_strdup(s)))
			return (NULL);
		i = 0;
		while (s[i])
		{
			mem[i] = f(i, s[i]);
			i++;
		}
		return (mem);
	}
	return (NULL);
}
