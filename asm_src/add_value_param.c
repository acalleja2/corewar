/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_value_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:47:55 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/18 21:42:42 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_value_param(t_param *par, int ret, t_instru *ins, t_instru *cur)
{
	int		rank;

	rank = search_rank_op(cur->opcode);
	if (ret == T_REG)
		add_rg_val(par);
	else if (ret == T_IND)
	{
		if (par->name[0] == LABEL_CHAR)
			par->ret = T_LAB;
		else
			par->value = ft_atoi(par->name);
		par->nb_octet = 2;
	}
	else if (ret == T_DIR)
	{
		if (par->name[1] == LABEL_CHAR)
			par->ret = T_LAB + 1;
		else
			par->value = ft_atoi(par->name + 1);
		if (g_op_tab[rank].nb_direct == 0)
			par->nb_octet = 4;
		else
			par->nb_octet = 2;
	}
}

void	add_rg_val(t_param *par)
{
	par->value = ft_atoi(par->name + 1);
	par->nb_octet = 1;
}
