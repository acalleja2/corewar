/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:45:58 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/28 13:30:46 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	size_t_case_int(t_info *info, va_list args)
{
	if (sizeof(size_t) == sizeof(int))
		process_int(info, (intmax_t)va_arg(args, int));
	else if (sizeof(size_t) == sizeof(long int))
		process_int(info, (intmax_t)va_arg(args, long int));
	else if (sizeof(size_t) == sizeof(short int))
		process_int(info, (intmax_t)((short int)va_arg(args, unsigned int)));
}

void		out_int(t_info *info, va_list args)
{
	if (info->size == -3)
		size_t_case_int(info, args);
	else if (info->size == -2)
		process_int(info, (intmax_t)((signed char)va_arg(args, unsigned int)));
	else if (info->size == -1)
		process_int(info, (intmax_t)((short int)va_arg(args, unsigned int)));
	else if (info->size == 0)
		process_int(info, (intmax_t)va_arg(args, int));
	else if (info->size == 1)
		process_int(info, (intmax_t)va_arg(args, long int));
	else if (info->size == 2)
		process_int(info, (intmax_t)va_arg(args, long long int));
	else if (info->size == 3)
		process_int(info, (intmax_t)va_arg(args, intmax_t));
}

void		put_int_sign(t_info *info, intmax_t n, char plussign)
{
	addchar(info, n < 0 ? '-' : plussign);
}

static void	zerop_int(t_info *info)
{
	if (info->plus)
		addchar(info, '+');
	else if (info->space)
		addchar(info, ' ');
	put_nchars(info, info->field - (info->space || info->plus), SPACE);
}

void		process_int(t_info *info, intmax_t n)
{
	int		fieldcpy;
	int		realpr;

	if (info->precision == 0 && n == 0)
		zerop_int(info);
	else if (info->precision >= 0)
	{
		info->zeroes = TRUE;
		fieldcpy = info->field;
		realpr = info->precision + (n < 0 || info->plus || info->space);
		info->field = (int_len(info, n) > realpr ? int_len(info, n) : realpr);
		if (info->leftjustify)
		{
			info->leftjustify = FALSE;
			print_int(info, n);
			put_nchars(info, fieldcpy - info->field, SPACE);
		}
		else
		{
			put_nchars(info, fieldcpy - info->field, SPACE);
			print_int(info, n);
		}
	}
	else
		print_int(info, n);
}
