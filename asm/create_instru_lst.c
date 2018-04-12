/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lab_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:23:55 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/11 15:56:07 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	create_intru_lst(t_instru **ins, char *op, t_label **lab, t_param **par)
{
	t_instru	*tmp;
	t_instru	*last;

	tmp = *ins;
	while (tmp->next)
		tmp = tmp->next;
	if (!*ins)
	{
		*ins = (t_instru *)malloc(sizeof(t_instru));
		(*ins)->opcode = ft_strdup(op);
		free(op);
		(*ins)->next = NULL;
	}
	else
	{
		last = (t_instru *)malloc(sizeof(t_instru));
		(last)->opcode = ft_strdup(op);
		free(op);
		(last)->next = NULL;
		tmp->next = last;
	}
}
