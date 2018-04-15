/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:17:55 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/15 19:14:39 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_param(t_instru *ins, t_label *lab, char *str, unsigned char octet)
{
	t_instru		*tmp;
	int			ret;
	int			i;
	int			rank;
	t_param		*t_par;

	ret = 0;
	tmp = ins;
	while (tmp)
	{
		i = 0;
		octet = 0;
		rank = search_rank_op(tmp->opcode);
		t_par = tmp->par;
		while (t_par)
		{
			ret = 0;
			str = ft_strdup(t_par->name);
			ret |= is_reg(str);
			ret |= is_direct(str, ins, lab, tmp);
			ret |= is_indirect(str, ins, lab, tmp);
			if (!(ret & op_tab[rank].param_type[i]))
				error_param();
			octet += write_ocp(ret, i);
			i++;
			free(str);
			t_par->ret = ret;
			add_param_size(&tmp, ret, rank);
			add_value_param(t_par, ret, ins, tmp);
			t_par = t_par->next;
		}
		if (op_tab[rank].ocp == 1)
			tmp->ocp = octet;
		add_size(&tmp, rank);
		tmp = tmp->next;
	}
}

