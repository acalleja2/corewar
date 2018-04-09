/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:17:26 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/28 13:51:13 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		printf_get_flags(t_info *info, va_list args)
{
	while (is_flag(**(info->fmt)))
	{
		if (**(info->fmt) == '+')
			info->plus = TRUE;
		else if (**(info->fmt) == '#')
			info->hash = TRUE;
		else if (**(info->fmt) == '-')
			info->leftjustify = TRUE;
		else if (**(info->fmt) == ' ')
			info->space = TRUE;
		else if (**(info->fmt) == '0')
			info->zeroes = TRUE;
		mv_fmt(info);
	}
	return (get_field(info, args));
}

int		get_field(t_info *info, va_list args)
{
	if (**(info->fmt) == '*')
	{
		info->field = va_arg(args, int);
		if (info->field < 0)
		{
			info->leftjustify = TRUE;
			if (info->field == INT_MIN)
				info->field = INT_MAX;
			else
				info->field = -(info->field);
		}
		mv_fmt(info);
	}
	else if (**(info->fmt) >= '1' && **(info->fmt) <= '9')
		info->field = fmt_to_num(info);
	return (get_precision(info, args));
}

int		get_precision(t_info *info, va_list args)
{
	if (**(info->fmt) == '.' || **(info->fmt) == '*')
	{
		info->precision = 0;
		if (**(info->fmt) == '.')
			mv_fmt(info);
		if (**(info->fmt) == '*')
		{
			info->precision = va_arg(args, int);
			mv_fmt(info);
		}
		else if (**(info->fmt) >= '0' && **(info->fmt) <= '9')
			info->precision = fmt_to_num(info);
	}
	return (get_sizemod(info));
}

int		get_sizemod(t_info *info)
{
	while (is_sizemod(**(info->fmt)))
	{
		if (**(info->fmt) == 'j')
			info->size = 3;
		else if (**(info->fmt) == 'z')
			info->size = -3;
		else if (**(info->fmt) == 'l' && (info->size == 0 || info->size == 1))
			info->size = info->size + 1;
		else if (**(info->fmt) == 'h' && (info->size == 0 || info->size == -1))
			info->size = info->size - 1;
		mv_fmt(info);
	}
	return (get_spec(info));
}

int		get_spec(t_info *info)
{
	if (**(info->fmt) == 'd' || **(info->fmt) == 'i')
		info->format = INT;
	else if (is_uintspec(**(info->fmt)))
		set_uint(info, **(info->fmt));
	else if (**(info->fmt) == 's')
		info->format = CHARPTR;
	else if (**(info->fmt) == 'c')
		info->format = CHAR;
	else if (**(info->fmt) == 'p')
		info->format = VOIDPTR;
	else if (**(info->fmt) == 'S')
		info->format = WCHARPTR;
	else if (**(info->fmt) == 'C')
		info->format = WCHAR;
	else if (**(info->fmt) == 'n')
		info->format = INTPTR;
	else if (**(info->fmt) == 'D' || **(info->fmt) == 'O' ||
			**(info->fmt) == 'U')
		shitty_case(info, **(info->fmt));
	else
		return (0);
	return (1);
}
