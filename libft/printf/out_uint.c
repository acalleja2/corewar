/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:53:03 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/27 18:53:03 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	size_t_case_uint(t_info *info, va_list args)
{
	if (sizeof(size_t) == sizeof(unsigned int))
		process_uint(info, (uintmax_t)va_arg(args, unsigned int));
	else if (sizeof(size_t) == sizeof(long unsigned int))
		process_uint(info, (uintmax_t)va_arg(args, long unsigned int));
	else if (sizeof(size_t) == sizeof(short unsigned int))
		process_uint(info,
				(uintmax_t)((short unsigned int)va_arg(args, unsigned int)));
}

void		out_uint(t_info *info, va_list args)
{
	if (info->size == -3)
		size_t_case_uint(info, args);
	else if (info->size == -2)
		process_uint(info,
				(uintmax_t)((unsigned char)va_arg(args, unsigned int)));
	else if (info->size == -1)
		process_uint(info,
				(uintmax_t)((short unsigned int)va_arg(args, unsigned int)));
	else if (info->size == 0)
		process_uint(info, (uintmax_t)va_arg(args, unsigned int));
	else if (info->size == 1)
		process_uint(info, (uintmax_t)va_arg(args, long unsigned int));
	else if (info->size == 2)
		process_uint(info, (uintmax_t)va_arg(args, long long unsigned int));
	else if (info->size == 3)
		process_uint(info, va_arg(args, uintmax_t));
}
