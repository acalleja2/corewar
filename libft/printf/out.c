/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:17:04 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/19 16:17:04 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** Debug
** dprintf(2, "\n");
** dprintf(2, "hash = %i\n", info->hash);
** dprintf(2, "leftjustify = %i\n", info->leftjustify);
** dprintf(2, "zeroes = %i\n", info->zeroes);
** dprintf(2, "plus = %i\n", info->plus);
** dprintf(2, "space = %i\n", info->space);
** dprintf(2, "field = %i\n", info->field);
** dprintf(2, "precision = %i\n", info->precision);
** dprintf(2, "size = %i\n", info->size);
** dprintf(2, "charlen = %i\n", info->charlen);
** dprintf(2, "base = %lu\n", info->base);
** dprintf(2, "caps = %i\n", info->caps);
** dprintf(2, "info->format = ");
** if (info->format == CHAR)
** dprintf(2, "CHAR");
** else if (info->format == INT)
** dprintf(2, "INT");
** else if (info->format == UINT)
** dprintf(2, "UINT");
** else if (info->format == WCHAR)
** dprintf(2, "WCHAR");
** else if (info->format == VOIDPTR)
** dprintf(2, "VOIDPTR");
** else if (info->format == CHARPTR)
** dprintf(2, "CHARPTR");
** else if (info->format == WCHARPTR)
** dprintf(2, "WCHARPTR");
** else if (info->format == INTPTR)
** dprintf(2, "INTPTR");
** dprintf(2, "\n");
*/

void		ft_out(t_info *info, va_list args)
{
	mv_fmt(info);
	if (info->format == INT)
		out_int(info, args);
	else if (info->format == CHARPTR)
		out_str(info, args);
	else if (info->format == UINT)
		out_uint(info, args);
	else if (info->format == VOIDPTR)
		out_voidptr(info, args);
	else if (info->format == CHAR)
		out_char(info, args);
	else if (info->format == WCHAR)
		out_wchar(info, args);
	else if (info->format == WCHARPTR)
		out_wstr(info, args);
	else if (info->format == INTPTR)
		set_count(info, args);
}
