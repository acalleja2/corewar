/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_parm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:32:57 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/13 16:04:44 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_reg(char *str)
{
	if (str[0] != 'r')
		return (0);
	del_pos(str, 0);
	if (!all_digit(str) || ft_atoi(str) > REG_NUMBER)
		return (0);
	return (T_REG);
}

int		is_direct(char *str, t_instru *beg, t_label *lab, t_instru *tmp)
{
	t_label		*l;

	if (str[0] != DIRECT_CHAR)
		return (0);
	del_pos(str, 0);
	if (str[0] != LABEL_CHAR)
	{
		if (str[0] == '-')
			del_pos(str, 0);
		if (all_digit(str))
			return (T_DIR);
	}
	else
	{
		del_pos(str, 0);
		while (beg)
		{
			l = beg->lab;
			while (l)
			{
				if (!ft_strcmp(l->name, str) && beg != tmp)
					return (T_DIR);
				l = l->next;
			}
			beg = beg->next;
		}
		while (lab)
		{
			if (!ft_strcmp(lab->name, str))
				return (T_DIR);
			lab = lab->next;
		}
		if (tmp && tmp->lab && !ft_strcmp(str, tmp->lab->name))
			return (T_DIR);
	}
	return (0);
}

int		is_indirect(char *str, t_instru *beg, t_label *lab, t_instru *tmp)
{
	t_label		*l;

	if (str[0] != LABEL_CHAR)
	{
		if (str[0] == '-')
			del_pos(str, 0);
		if (all_digit(str))
			return (T_IND);
	}
	else
	{
		del_pos(str, 0);
		while (beg)
		{
			l = beg->lab;
			while (l)
			{
				if (!ft_strcmp(l->name, str) && beg != tmp)
					return (T_IND);
				l = l->next;
			}
			beg = beg->next;
		}
		while (lab)
		{
			if (!ft_strcmp(lab->name, str))
				return (T_IND);
			lab = lab->next;
		}
		if (tmp && tmp->lab && !ft_strcmp(str, tmp->lab->name))
			return (T_IND);
	}
	return (0);
}
