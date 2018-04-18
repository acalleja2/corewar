/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:17:55 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/18 21:43:12 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_param2(t_instru *ins, t_label *lab, t_instru *tmp, int rank)
{
	unsigned char	octet;
	int				ret;
	int				i;
	char			*str;
	t_param			*t_par;

	i = 0;
	octet = 0;
	t_par = tmp->par;
	while (t_par)
	{
		str = ft_strdup(t_par->name);
		ret = ret_val(str, ins, lab, tmp);
		if (!(ret & g_op_tab[rank].param_type[i]))
			error_param();
		octet += write_ocp(ret, i);
		i++;
		free(str);
		t_par->ret = ret;
		add_param_size(&tmp, ret, rank);
		add_value_param(t_par, ret, ins, tmp);
		t_par = t_par->next;
	}
	if (g_op_tab[rank].ocp == 1)
		tmp->ocp = octet;
}

void	check_param(t_instru *ins, t_label *lab)
{
	t_instru	*tmp;
	int			rank;

	tmp = ins;
	while (tmp)
	{
		rank = search_rank_op(tmp->opcode);
		check_param2(ins, lab, tmp, rank);
		add_size(&tmp, rank);
		tmp = tmp->next;
	}
}

int		ret_val(char *str, t_instru *ins, t_label *lab, t_instru *tmp)
{
	int		ret;

	ret = 0;
	ret |= is_reg(str);
	ret |= is_direct(str, ins, lab, tmp);
	ret |= is_indirect(str, ins, lab, tmp);
	return (ret);
}
