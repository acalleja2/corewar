/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_opcode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:23:05 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/12 18:57:29 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	pars_opcode(char *str, t_instru **ins)
{
	char	**tab2;
	char	**tab;
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		del_pos(str, 0);
	tab2 = ft_strsplit(str, ' ');
	tab = ft_strsplit(tab2[0], '\t');
	(*ins)->opcode = ft_strdup(tab[0]);
	while (i < ft_strlen(tab[0]))
	{
		del_pos(str, 0);
		i++;
	}
	free_tab(tab);
}
