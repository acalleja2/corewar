/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:19:34 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/21 16:43:46 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_reg(char *s)
{
	char	*str;

	str = ft_strdup(s);
	if (str[0] != 'r')
	{
		free(str);
		return (0);
	}
	del_pos(str, 0);
	if (!all_digit(str) || er_atoi(str) > REG_NUMBER)
	{
		free(str);
		return (0);
	}
	free(str);
	return (T_REG);
}
