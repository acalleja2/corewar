/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:01:57 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/16 19:35:55 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	pars_param(char *str, t_instru **ins)
{
	char	**tab;
	int		i;
	t_param	*tmp;
	char	*cpy;

	i = 0;
	tmp = NULL;
	tab = ft_strsplit(str, SEPARATOR_CHAR);
	if ((count_sep(str) + 1) != len_tab(tab))
		error_param();
	while (i < len_tab(tab))
	{
		cpy = ft_strtrim(tab[i]);
		create_param_lst(&tmp, cpy);
		free(cpy);
		i++;
	}
	(*ins)->par = tmp;
	free_tab(tab);
}
