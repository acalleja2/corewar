/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ocp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 22:27:18 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/18 21:44:44 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	write_ocp(int ret, int i)
{
	char	octet;

	octet = 0;
	if (ret == T_REG)
	{
		octet |= 1;
		octet = octet << (6 - i * 2);
	}
	else if (ret == T_IND)
	{
		octet |= 3;
		octet = octet << (6 - i * 2);
	}
	else
	{
		octet |= 2;
		octet = octet << (6 - i * 2);
	}
	return (octet);
}
