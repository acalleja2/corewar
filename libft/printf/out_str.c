/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:14:59 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/28 13:48:51 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			charptrlen(t_info *info, char *str)
{
	int		len;

	len = 0;
	if (info->precision == 0)
		return (0);
	else if (info->precision > 0)
		while (len < info->precision && str[len])
			len += 1;
	else
		while (str[len])
			len += 1;
	return (len);
}

void		print_str(t_info *info, char *str)
{
	int		pos;

	pos = 0;
	while (pos < info->charlen)
	{
		addchar(info, str[pos]);
		pos += 1;
	}
}

void		out_str(t_info *info, va_list args)
{
	char	*str;

	if (info->size > 0)
	{
		out_wstr(info, args);
		return ;
	}
	str = va_arg(args, char*);
	if (str == NULL)
		str = "(null)";
	info->charlen = charptrlen(info, str);
	if (info->leftjustify)
	{
		print_str(info, str);
		put_nchars(info, info->field - info->charlen, SPACE);
	}
	else
	{
		put_nchars(info, info->field - info->charlen,
				info->zeroes ? '0' : SPACE);
		print_str(info, str);
	}
}
