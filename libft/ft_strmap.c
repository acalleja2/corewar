/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 02:29:35 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/15 14:41:47 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			mem[i] = f(mem[i]);
			i++;
		}
		return (mem);
	}
	return (NULL);
}
