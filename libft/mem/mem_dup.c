/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:45:36 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/13 19:45:36 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*mem_dup(void *ptr, size_t size)
{
	unsigned char	*new;
	size_t			pos;

	if (size == 0)
		return (NULL);
	new = ealloc(size);
	pos = 0;
	while (pos < size)
	{
		new[pos] = *((char*)ptr + pos);
		pos += 1;
	}
	return (new);
}
