/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:28:23 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/28 13:47:33 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		out_char(t_info *info, va_list args)
{
	char	c;

	if (info->size > 0)
	{
		out_wchar(info, args);
		return ;
	}
	c = (signed char)(va_arg(args, int));
	if (info->leftjustify)
	{
		addchar(info, c);
		put_nchars(info, info->field - 1, SPACE);
	}
	else
	{
		put_nchars(info, info->field - 1, info->zeroes ? '0' : SPACE);
		addchar(info, c);
	}
}
