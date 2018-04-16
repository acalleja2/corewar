/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_parm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:32:57 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/16 14:43:32 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_reg(char *s)
{
	char	*str;

	str = ft_strdup(s);
	if (str[0] != 'r')
	{
		free(str);
		return (0);
	}
	del_pos(str, 0);
	if (!all_digit(str) || ft_atoi(str) > REG_NUMBER)
	{
		free(str);
		return (0);
	}
	free(str);
	return (T_REG);
}

int		is_direct(char *s, t_instru *beg, t_label *lab, t_instru *tmp)
{
	t_label		*l;
	char	*str;

	str = ft_strdup(s);
	if (str[0] != DIRECT_CHAR || str[0] == 'r')
	{
		free(str);
		return (0);
	}
	del_pos(str, 0);
	if (str[0] != LABEL_CHAR)
	{
		if (str[0] == '-')
			del_pos(str, 0);
		if (all_digit(str))
		{
			free(str);
			return (T_DIR);
		}
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
				{
					free(str);
					return (T_DIR);
				}
				l = l->next;
			}
			beg = beg->next;
		}
		while (lab)
		{
			if (!ft_strcmp(lab->name, str))
			{
				free(str);
				return (T_DIR);
			}
			lab = lab->next;
		}
		if (tmp && tmp->lab && !ft_strcmp(str, tmp->lab->name))
		{
			free(str);
			return (T_DIR);
		}
	}
	return (0);
}

int		is_indirect(char *s, t_instru *beg, t_label *lab, t_instru *tmp)
{
	t_label		*l;
	char	*str;

	str = ft_strdup(s);
	if (str[0] == 'r')
	{
		free(str);
		return (0);
	}
	if (str[0] != LABEL_CHAR)
	{
		if (str[0] == '-')
			del_pos(str, 0);
		if (all_digit(str))
		{
			free(str);
			return (T_IND);
		}
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
				{
					free(str);
					return (T_IND);
				}
				l = l->next;
			}
			beg = beg->next;
		}
		while (lab)
		{
			if (!ft_strcmp(lab->name, str))
			{
				free(str);
				return (T_IND);
			}
			lab = lab->next;
		}
		if (tmp && tmp->lab && !ft_strcmp(str, tmp->lab->name))
		{
			free(str);
			return (T_IND);
		}
	}
	free(str);
	return (0);
}
