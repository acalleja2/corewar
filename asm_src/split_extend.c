/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_extend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:39:56 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/18 14:54:59 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*split_extend(char **tab, int len)
{
	int		i;
	char	*name;
	char	*tmp;

	i = 0;
	name = ft_strnew(0);
	while (i < len - 1)
	{
		tmp = name;
		name = ft_strjoin(name, tab[i]);
		free(tmp);
		i++;
	}
	return (name);
}
