/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:09:46 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/13 11:53:08 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_nb_param(t_instru *ins)
{
	int		rank;
	int		nb_par;

	rank = search_rank_op(ins->opcode);
	if ((nb_par = count_lst_par(ins->par)) != op_tab[rank].param_num)
		error_param();
	
}
