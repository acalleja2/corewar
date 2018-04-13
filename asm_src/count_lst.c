/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:44:40 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/13 11:23:48 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		count_lst_lab(t_label *lab)
{
	int		i;

	i = 0;
	while (lab)
	{
		lab = lab->next;
		i++;
	}
	return (i);
}

int		count_lst_ins(t_instru *ins)
{
	int		i;

	i = 0;
	while (ins)
	{
		ins = ins->next;
		i++;
	}
	return (i);
}

int		count_lst_par(t_param *par)
{
	int		i;

	i = 0;
	while (par)
	{
		par = par->next;
		i++;
	}
	return (i);
}
