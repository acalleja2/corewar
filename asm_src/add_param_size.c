/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_param_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:05:16 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/18 20:53:42 by acalleja         ###   ########.fr       */
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
		if (op_tab[rank].nb_direct == 0)
			(*tmp)->size += 4;
		else
			(*tmp)->size += 2;
	}
}
