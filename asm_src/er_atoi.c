/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   er_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:33:13 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/21 16:36:27 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Les overflow c'est un coup du pute
*/

static void	raise_overflow_error(void)
{
	ft_printf("IT'S OVER 9000 !!!\n");
	exit(EXIT_FAILURE);
}

int			er_atoi(const char *str)
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
			raise_overflow_error();
	}
	res *= neg;
	return ((int)res);
}
