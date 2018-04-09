/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:07:50 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/23 12:07:50 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				wstr_byte_len(wchar_t *ptr)
{
	int			len;

	len = 0;
	while (*ptr)
	{
		len += wchar_len(*ptr);
		ptr += 1;
	}
	return (len);
}

int				wstr_byte_nlen(wchar_t *ptr, int n)
{
	int			len;
	int			width;

	len = 0;
	while (*ptr)
	{
		width = wchar_len(*ptr);
		if (len + width > n)
			break ;
		len += width;
		ptr += 1;
	}
	return (len);
}

void			add_wstr(t_info *info, wchar_t *ptr)
{
	int			bytes_written;
	int			width;

	bytes_written = 0;
	while (bytes_written < info->charlen)
	{
		width = wchar_len(*ptr);
		add_wchar(info, *ptr, width);
		bytes_written += width;
		ptr += 1;
	}
}

void			out_wstr(t_info *info, va_list args)
{
	wchar_t		*ptr;

	ptr = va_arg(args, wchar_t *);
	if (!ptr)
	{
		addmsg(info, "(null)");
		return ;
	}
	info->charlen = (info->precision < 0 ? wstr_byte_len(ptr) :
			wstr_byte_nlen(ptr, info->precision));
	if (info->leftjustify)
	{
		add_wstr(info, ptr);
		put_nchars(info, info->field - info->charlen, SPACE);
	}
	else
	{
		put_nchars(info, info->field - info->charlen, SPACE);
		add_wstr(info, ptr);
	}
}
