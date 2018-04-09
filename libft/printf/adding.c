/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:17:11 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/23 17:17:11 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		addchar(t_info *info, char c)
{
	if (!(info->max) || (info->max && info->total < (int)info->max))
	{
		(*(info->show))(0, 0, 0, c);
	}
	info->total += 1;
}

void		put_nchars(t_info *info, int n, char c)
{
	while (n > 0)
	{
		addchar(info, c);
		n -= 1;
	}
}

void		addmsg(t_info *info, char *str)
{
	while (*str)
	{
		addchar(info, *str);
		str += 1;
	}
}
