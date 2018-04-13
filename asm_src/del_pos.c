/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:14:36 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/13 20:14:48 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	del_pos(char *str, int pos)
{
	while (str[pos + 1])
	{
		str[pos] = str[pos + 1];
		pos++;
	}
	str[pos] = '\0';
}

void	del_seq(char *str, int pos, int seq)
{
	int		i;

	i = 0;
	while (i < seq)
	{
		del_pos(str, pos);
		i++;
	}
}
