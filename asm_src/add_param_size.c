/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_param_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:05:16 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/21 13:34:18 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_param_size(t_instru **tmp, int ret, int rank)
{
	if (ret == T_REG)
		(*tmp)->size += 1;
	else if (ret == T_IND)
		(*tmp)->size += 2;
	else
	{
		if (g_op_tab[rank].nb_direct == 0)
			(*tmp)->size += 4;
		else
			(*tmp)->size += 2;
	}
}
