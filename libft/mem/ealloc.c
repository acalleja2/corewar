/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ealloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 20:13:12 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/09 20:13:12 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Le wrapper de la mort
** Check les mallocs a ta place
*/

void		*ealloc(size_t size)
{
	void	*res;

	if (size == 0)
		return (NULL);
	res = malloc(size);
	if (res == NULL)
	{
		perror("An error occured ");
		exit(EXIT_FAILURE);
	}
	return (res);
}
