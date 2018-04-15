/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lab_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:23:55 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/15 15:12:04 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	create_instru_lst(t_instru **ins)
{
	t_instru	*tmp;
	t_instru	*last;

	tmp = *ins;
	if (!*ins)
	{
		*ins = (t_instru *)ealloc(sizeof(t_instru));
		(*ins)->next = NULL;
		(*ins)->size = 0;
		(*ins)->ocp = 0;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		last = (t_instru *)ealloc(sizeof(t_instru));
		last->size = 0;
		last->ocp = 0;
		(last)->next = NULL;
		tmp->next = last;
	}
}
