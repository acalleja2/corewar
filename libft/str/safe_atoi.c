/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 23:35:37 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/20 23:35:37 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Tente un atoi pour un int, renvoie 1 en cas d'overflow
*/

int		safe_atoi(const char *str, int *result)
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
		if (res > (intmax_t)INT_MAX || res < (intmax_t)INT_MIN)
			return (1);
	}
	res += neg;
	*result = (int)res;
	return (0);
}
