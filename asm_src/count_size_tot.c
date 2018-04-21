/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_size_tot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:50:35 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/21 13:34:08 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		count_size_tot(t_instru *tmp)
{
	int		count;

	count = 0;
	while (tmp)
	{
		count += tmp->size;
		tmp = tmp->next;
	}
	return (count);
}
