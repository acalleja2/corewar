/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 13:26:02 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/28 13:36:46 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/* static void		zero_case(t_info *info) */
/* { */
/* 	if (info->precision >= 0) */
/* 	{ */
/* 		if (info->leftjustify) */
/* 		{ */
/* 			put_nchars(info, info->precision, '0'); */
/* 			put_nchars(info, info->field - info->precision, SPACE); */
/* 		} */
/* 		else */
/* 		{ */
/* 			put_nchars(info, info->field - info->precision, */
/* 					info->zeroes ? '0' : SPACE); */
/* 			put_nchars(info, info->precision, '0'); */
/* 		} */
/* 		return ; */
/* 	} */
/* 	if (info->leftjustify) */
/* 	{ */
/* 		addchar(info, '0'); */
/* 		put_nchars(info, info->field - 1, SPACE); */
/* 	} */
/* 	else */
/* 	{ */
/* 		put_nchars(info, info->field - 1, info->zeroes ? '0' : SPACE); */
/* 		addchar(info, '0'); */
/* 	} */
/* } */

static void		precision_case(t_info *info, uintmax_t n)
{
	if (info->leftjustify)
	{
		uint_prefix(info);
		put_nchars(info, info->precision - info->charlen, '0');
		uint_base(info, n);
		put_nchars(info,
				info->field - info->precision - prefix_len(info), SPACE);
		return ;
	}
	if (info->zeroes)
	{
		uint_prefix(info);
		put_nchars(info,
				info->field - info->precision - prefix_len(info), '0');
		put_nchars(info, info->precision - info->charlen, '0');
		uint_base(info, n);
	}
	else
	{
		put_nchars(info,
				info->field - info->precision - prefix_len(info), SPACE);
		uint_prefix(info);
		put_nchars(info, info->precision - info->charlen, '0');
		uint_base(info, n);
	}
}

static void		normal_case(t_info *info, uintmax_t n)
{
	if (info->leftjustify)
	{
		uint_prefix(info);
		uint_base(info, n);
		put_nchars(info, info->field - info->charlen - prefix_len(info), SPACE);
	}
	else
	{
		if (info->zeroes)
		{
			uint_prefix(info);
			put_nchars(info,
					info->field - info->charlen - prefix_len(info), '0');
			uint_base(info, n);
		}
		else
		{
			put_nchars(info,
					info->field - info->charlen - prefix_len(info), SPACE);
			uint_prefix(info);
			uint_base(info, n);
		}
	}
}

void			process_uint(t_info *info, uintmax_t n)
{
	info->charlen = uint_digits(info, n);
	if (info->precision >= 0)
	{
		info->zeroes = FALSE;
	}
	if (info->base == 8 && info->hash)
	{
		info->hash = FALSE;
		if (info->precision <= info->charlen && n != 0)
			info->precision = info->charlen + 1;
		if (info->precision == 0)
			info->precision = 1;
	}
	/* if (n == 0) */
		/* zero_case(info); */
	else if (info->precision >= 0 && info->precision > info->charlen)
		precision_case(info, n);
	else
		normal_case(info, n);
}
