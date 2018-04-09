/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_voidptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:31:50 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/28 13:33:54 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	null_case(t_info *info)
{
	if (info->leftjustify)
	{
		addmsg(info, "0x");
		put_nchars(info, info->precision >= 0 ? info->precision : 1, '0');
		put_nchars(info, info->field - 3, SPACE);
	}
	else
	{
		put_nchars(info, info->field - 3, SPACE);
		addmsg(info, "0x");
		put_nchars(info, info->precision >= 0 ? info->precision : 1, '0');
	}
}

void		out_voidptr(t_info *info, va_list args)
{
	void	*ptr;

	ptr = (va_arg(args, void*));
	if (ptr == NULL)
	{
		null_case(info);
		return ;
	}
	info->hash = TRUE;
	info->base = 16;
	if (sizeof(void*) == sizeof(long))
	{
		info->size = 1;
		process_uint(info, (unsigned long)ptr);
	}
	else
	{
		info->size = 0;
		process_uint(info, (unsigned int)ptr);
	}
}
