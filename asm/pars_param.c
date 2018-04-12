/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:01:57 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/11 19:09:51 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	pars_param(char *str, t_instru **ins)
{
	char	**tab;
	int		i;
	t_instru *tmp;

	tmp = *ins;
	i = 0;
	tab = ft_strsplit(str, SEPARATOR_CHAR);
	while (i < len_tab(tab))
	{
		tmp->par->name = ft_strtrim(tab[i]);
		tmp->par = tmp->par->next;
		i++;
	}
	free_tab(tab);
}
