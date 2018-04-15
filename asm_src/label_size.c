/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:21:06 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/15 19:26:35 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		label_size(t_instru *ins, t_instru *cur, char *str)
{
	t_instru	*tmp;
	t_label		*lab;
	int			after;
	int			before;
	int			size;

	size = 0;
	after = 0;
	before = 0;
	tmp = ins;
	while (tmp)
	{
		if (tmp == cur)
		{
			if (size != 0)
				return (-size);
			if (before == 0)
				after = 1;
		}
		else
		{
			lab = tmp->lab;
			while (lab)
			{
				printf("%s\n", str);
				if (!ft_strcmp(lab->name, str))
				{
					if (size != 0)
						return (size);
					if (after == 0)
						before = 1;
				}
				lab = lab->next;
			}
		}
		if (after == 1 || before == 1)
		{
			size += tmp->size;
			printf("sizeo = %d\n", size);
		}
		tmp = tmp->next;
	}
	return (0);
}
