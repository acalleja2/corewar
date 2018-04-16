/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:21:37 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/16 14:13:44 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_lab(t_label **lab)
{
	t_label		*tmp;

	while (*lab)
	{
		tmp = (*lab)->next;
		free((*lab)->name);
		free(*lab);
		*lab = tmp;
	}
}

void	free_param(t_param **par)
{
	t_param		*tmp;

	while (*par)
	{
		tmp = (*par)->next;
		free((*par)->name);
		free(*par);
		*par = tmp;
	}
}

void	free_instru(t_instru **ins)
{
	t_instru	*tmp;

	while (*ins)
	{
		tmp = (*ins)->next;
		free((*ins)->opcode);
		free_lab(&(*ins)->lab);
		free_param(&(*ins)->par);
		free(*ins);
		*ins = tmp;
	}
}
