/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_param_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:36:33 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/12 17:36:51 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	create_param_lst(t_param **par, char *str)
{
	t_param		*tmp;
	t_param		*last;

	if (!str)
		return ;
	tmp = *par;
	if (!*par)
	{

		*par = (t_param *)ealloc(sizeof(t_param));
		(*par)->name = ft_strdup(str);
		(*par)->next = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		last = (t_param *)ealloc(sizeof(t_param));
		(last)->name = ft_strdup(str);
		(last)->next = NULL;
		tmp->next = last;
	}
}
