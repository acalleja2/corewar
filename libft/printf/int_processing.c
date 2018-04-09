/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:46:15 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/28 13:28:51 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		put_int_rec(t_info *info, intmax_t n)
{
	if (n <= -10)
		put_int_rec(info, n / 10);
	addchar(info, 48 - n % 10);
}

void		put_int(t_info *info, intmax_t n, int sign)
{
	if (n < 0)
	{
		if (sign)
			addchar(info, '-');
		put_int_rec(info, n);
	}
	else
		put_int_rec(info, -n);
}

int			int_len(t_info *info, intmax_t n)
{
	int		len;

	if (!n)
		return (info->plus || info->space ? 2 : 1);
	len = 1;
	if (n < 0 || info->plus || info->space)
		len += 1;
	n = n / 10;
	while (n)
	{
		len += 1;
		n = n / 10;
	}
	return (len);
}

static void	print_int_right(t_info *info, intmax_t n)
{
	if (info->zeroes)
	{
		if (((info->space || info->plus) && n >= 0) || n < 0)
			put_int_sign(info, n, info->plus ? PLUS : SPACE);
		put_nchars(info, info->field - info->charlen, '0');
		put_int(info, n, NOSIGN);
	}
	else
	{
		put_nchars(info, info->field - info->charlen, ' ');
		if ((info->plus || info->space) && n >= 0)
			addchar(info, info->plus ? PLUS : SPACE);
		put_int(info, n, SIGN);
	}
}

void		print_int(t_info *info, intmax_t n)
{
	info->charlen = int_len(info, n);
	if (info->leftjustify)
	{
		if ((info->plus || info->space) && n >= 0)
			addchar(info, info->plus ? PLUS : SPACE);
		put_int(info, n, SIGN);
		put_nchars(info, info->field - info->charlen, SPACE);
	}
	else
		print_int_right(info, n);
}
