/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:50:11 by florenzo          #+#    #+#             */
/*   Updated: 2018/03/10 16:50:11 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** free() n elements
** Renvoie NULL, pratique pour quitter une fonction
** Exemple :
** freen(5, ptr1, ptr2, str, lst->next, lst);
*/

void			*freen(int n, ...)
{
	va_list		ptrs;

	va_start(ptrs, n);
	while (n-- > 0)
		free(va_arg(ptrs, void*));
	va_end(ptrs);
	return (NULL);
}
