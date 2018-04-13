/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:01:57 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/13 21:41:20 by acalleja         ###   ########.fr       */
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
	while (i < len_tab(tab))
	{
		cpy = ft_strtrim(tab[i]);
		create_param_lst(&tmp, cpy);
		free(cpy);
		i++;
	}
	(*ins)->par = tmp;
}
