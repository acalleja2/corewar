/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:15:47 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/09 21:02:45 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	char	*cpy;

	ptr = (char*)ealloc(sizeof(char) * size + 1);
	if (!ptr)
		return (NULL);
	cpy = ptr;
	while (size)
	{
		*ptr = '\0';
		++ptr;
		--size;
	}
	*ptr = '\0';
	return (cpy);
}
