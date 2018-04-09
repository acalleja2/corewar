/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_cinstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:05:50 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/06 17:08:27 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check si un char est dans la chaine
*/

int		ft_is_cinstr(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (TRUE);
		str += 1;
	}
	return (FALSE);
}
