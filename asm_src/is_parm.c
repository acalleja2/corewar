/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_parm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:32:57 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/18 21:06:11 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_direct(char *s, t_instru *beg, t_label *lab, t_instru *tmp)
{
	t_label		*l;
	char		*str;

	str = ft_strdup(s);
	if (str[0] != DIRECT_CHAR || str[0] == 'r')
		return (ret_dir_ind(str, 0));
	del_pos(str, 0);
	if (str[0] != LABEL_CHAR)
	{
		if (str[0] == '-')
			del_pos(str, 0);
		if (all_digit(str))
			return (ret_dir_ind(str, T_DIR));
	}
	else
		return (is_direct2(str, beg, lab, tmp));
	return (0);
}

int		is_direct2(char *str, t_instru *beg, t_label *lab, t_instru *tmp)
{
	t_label		*l;

	del_pos(str, 0);
	while (beg)
	{
		l = beg->lab;
		while (l)
		{
			if (!ft_strcmp(l->name, str) && beg != tmp)
				return (ret_dir_ind(str, T_DIR));
			l = l->next;
		}
		beg = beg->next;
	}
	while (lab)
	{
		if (!ft_strcmp(lab->name, str))
			return (ret_dir_ind(str, T_DIR));
		lab = lab->next;
	}
	if (tmp && tmp->lab && !ft_strcmp(str, tmp->lab->name))
		return (ret_dir_ind(str, T_DIR));
	return (0);
}

int		ret_dir_ind(char *str, int val)
{
	free(str);
	return (val);
}

int		is_indirect2(char *str, t_instru *beg, t_label *lab, t_instru *tmp)
{
	t_label		*l;

	del_pos(str, 0);
	while (beg)
	{
		l = beg->lab;
		while (l)
		{
			if (!ft_strcmp(l->name, str) && beg != tmp)
				return (ret_dir_ind(str, T_DIR));
			l = l->next;
		}
		beg = beg->next;
	}
	while (lab)
	{
		if (!ft_strcmp(lab->name, str))
			return (ret_dir_ind(str, T_DIR));
		lab = lab->next;
	}
	if (tmp && tmp->lab && !ft_strcmp(str, tmp->lab->name))
		return (ret_dir_ind(str, T_DIR));
	return (0);
}

int		is_indirect(char *s, t_instru *beg, t_label *lab, t_instru *tmp)
{
	t_label		*l;
	char		*str;

	str = ft_strdup(s);
	if (str[0] == 'r')
		return (ret_dir_ind(str, 0));
	if (str[0] != LABEL_CHAR)
	{
		if (str[0] == '-')
			del_pos(str, 0);
		if (all_digit(str))
			return (ret_dir_ind(str, T_IND));
	}
	else
		return (is_indirect2(str, beg, lab, tmp));
	free(str);
	return (0);
}
