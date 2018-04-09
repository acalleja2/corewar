/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 19:06:48 by florenzo          #+#    #+#             */
/*   Updated: 2018/02/03 19:06:48 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Renvoie un intmax_t, pratique pour comparer avec INT_MAX
*/

intmax_t		ft_atoim(const char *str)
{
	intmax_t	res;
	intmax_t	neg;

	res = 0;
	neg = 1;
	while (ft_is_toskip(*str))
		str++;
	neg = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (neg * res);
}
