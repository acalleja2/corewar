/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:11:33 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/28 12:16:13 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		mv_fmt(t_info *info)
{
	*(info->fmt) = *(info->fmt) + 1;
}

void		parsechar(t_info *info, int n)
{
	addchar(info, **(info->fmt));
	while (n)
	{
		mv_fmt(info);
		n -= 1;
	}
}

int			printf_core(t_out *out,
						size_t max, const char *format, va_list args)
{
	t_info	info;

	init(out, max, &info, (char**)&format);
	while (*format)
	{
		if (*format == '%')
			if (*(format + 1) == '%')
				parsechar(&info, 2);
			else
			{
				if (format_acquired(&info, args))
					ft_out(&info, args);
				else
				{
					if (*format == '\0')
						break ;
					else
						parsechar(&info, 1);
				}
			}
		else
			parsechar(&info, 1);
	}
	flush(out, &info);
	return (info.total);
}
