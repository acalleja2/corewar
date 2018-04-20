/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parm_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 16:16:23 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/18 21:44:19 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_param_fd(t_instru *ins, int fd)
{
	t_instru	*tmp;
	t_param		*tmp_par;
	int			rank;

	tmp = ins;
	while (tmp)
	{
		rank = search_rank_op(tmp->opcode);
		write(fd, (char *)&g_op_tab[rank].opcode, 1);
		tmp_par = tmp->par;
		if (tmp->ocp != 0)
			write(fd, (char *)&tmp->ocp, 1);
		while (tmp_par)
		{
			rev_param(tmp_par->nb_octet, tmp_par->value, fd);
			tmp_par = tmp_par->next;
		}
		tmp = tmp->next;
	}
}
