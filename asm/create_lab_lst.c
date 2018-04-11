/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lab_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:23:55 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/11 15:44:48 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	create_lab_lst(t_label **lab, char *str)
{
	t_label		*tmp;
	t_label		*last;

	if (!str)
		return;
	tmp = *lab;
	while (tmp->next)
		tmp = tmp->next;
	if (!*lab)
	{
		*lab = (t_label *)malloc(sizeof(t_label));
		(*lab)->name = ft_strdup(str);
		free(str);
		(*lab)->next = NULL;
	}
	else
	{
		last = (t_label *)malloc(sizeof(t_label));
		(last)->name = ft_strdup(str);
		free(str);
		(last)->next = NULL;
		tmp->next = last;
	}
}
