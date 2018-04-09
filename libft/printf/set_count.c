/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:12:49 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/23 17:12:49 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			set_count(t_info *info, va_list args)
{
	int			*dest;

	dest = va_arg(args, int*);
	if (dest == NULL)
		return ;
	*dest = info->total;
}
