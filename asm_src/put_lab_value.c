/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lab_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 19:04:04 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/15 19:27:15 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	put_lab_value(t_instru *ins)
{
	t_instru	*tmp;
	t_param		*par;

	tmp = ins;
	while (tmp)
	{
		par = tmp->par;
		while (par)
		{
			if (par->ret == T_LAB)
				par->value = label_size(ins, tmp, par->name + 1);
			else if (par->ret == T_LAB + 1)
				par->value = label_size(ins, tmp, par->name + 2);
			par = par->next;
		}
		tmp = tmp->next;
	}
}
