/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:11:41 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/28 13:49:18 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			format_acquired(t_info *info, va_list args)
{
	reinit(info);
	mv_fmt(info);
	if (is_flag(**(info->fmt)))
		return (printf_get_flags(info, args));
	if ((**(info->fmt) >= '1' && **(info->fmt) <= '9') || **(info->fmt) == '*')
		return (get_field(info, args));
	if (**(info->fmt) == '.')
		return (get_precision(info, args));
	if (is_sizemod(**(info->fmt)))
		return (get_sizemod(info));
	if (is_spec(**(info->fmt)))
		return (get_spec(info));
	return (FALSE);
}

void		reinit(t_info *info)
{
	info->hash = FALSE;
	info->leftjustify = FALSE;
	info->zeroes = FALSE;
	info->plus = FALSE;
	info->space = FALSE;
	info->field = 0;
	info->precision = -1;
	info->size = 0;
	info->charlen = 0;
	info->base = 10;
	info->caps = FALSE;
}

int			fmt_to_num(t_info *info)
{
	int		res;

	res = 0;
	while (**(info->fmt) >= '0' && **(info->fmt) <= '9')
	{
		res = res * 10 + **(info->fmt) - 48;
		mv_fmt(info);
	}
	if (res < 0)
	{
		if (res == INT_MIN)
			res = INT_MAX;
		else
			res = -res;
	}
	return (res);
}

void		set_uint(t_info *info, char c)
{
	info->format = UINT;
	if (c == 'x' || c == 'X')
	{
		info->base = 16;
		info->caps = (c == 'X');
	}
	else if (c == 'o')
		info->base = 8;
	else if (c == 'b' || c == 'B')
	{
		info->base = 2;
		info->caps = (c == 'B');
	}
}

void		shitty_case(t_info *info, char c)
{
	info->size = 1;
	if (c == 'D')
		info->format = INT;
	else
	{
		info->format = UINT;
		if (c == 'O')
			info->base = 8;
	}
}
