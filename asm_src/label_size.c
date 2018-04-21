/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:21:06 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/21 17:58:49 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	label_size3(t_label *t_lab, char *str, int size)
{
	t_label		*lab;

	lab = t_lab;
	while (lab)
	{
		if (!ft_strcmp(str, lab->name))
			return (size);
		lab = lab->next;
	}
	return (0);
}

int			label_size(t_instru *ins, t_instru *cur, char *str, t_label *lab)
{
	t_instru	*tmp;
	int			bol[3];
	int			ret;

	bol[0] = 0;
	bol[1] = 0;
	bol[2] = 0;
	tmp = ins;
	while (tmp)
	{
		ret = label_size2(tmp, cur, str, bol);
		if (ret == -1)
			return (-bol[2]);
		else if (ret == 1)
			return (bol[2]);
		if (bol[1] == 1 || bol[0] == 1)
			bol[2] += tmp->size;
		tmp = tmp->next;
	}
	return (label_size3(lab, str, bol[2]));
}

int			label_size2(t_instru *tmp, t_instru *cur, char *str, int *bol)
{
	t_label		*lab;

	if (tmp == cur)
	{
		if (bol[2] != 0)
			return (-1);
		if (bol[0] == 0)
			bol[1] = 1;
	}
	else
	{
		lab = tmp->lab;
		while (lab)
		{
			if (!ft_strcmp(lab->name, str))
			{
				if (bol[2] != 0)
					return (1);
				if (bol[1] == 0)
					bol[0] = 1;
			}
			lab = lab->next;
		}
	}
	return (0);
}
