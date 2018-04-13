/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:16:52 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/12 15:40:34 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_lab(t_label *lab)
{
	while (lab)
	{
		ft_printf(" %s ", lab->name);
		lab = lab->next;
	}
}

void	print_par(t_param *par)
{
	while (par)
	{
		ft_printf(" %s ", par->name);
		par = par->next;
	}
}

void	print_ins(t_instru *ins)
{
	while (ins)
	{
		ft_printf("label =");
		print_lab(ins->lab);
		ft_printf(" || ");
		ft_printf("param =");
		print_par(ins->par);
		ft_printf(" || opcode = %s\n", ins->opcode);
		ins = ins->next;
	}
}
