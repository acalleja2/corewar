/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 19:57:26 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/28 19:57:26 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		uint_digits(t_info *info, uintmax_t n)
{
	int		len;

	len = 1;
	while (n >= info->base)
	{
		len += 1;
		n /= info->base;
	}
	return (len);
}

void	uint_prefix(t_info *info)
{
	if (!info->hash || info->base == 10 || info->base == 8)
		return ;
	else if (info->base == 16)
	{
		if (info->caps)
			addmsg(info, "0X");
		else
			addmsg(info, "0x");
	}
	else
	{
		if (info->caps)
			addmsg(info, "0B");
		else
			addmsg(info, "0b");
	}
}

int		prefix_len(t_info *info)
{
	if (!info->hash || info->base == 10 || info->base == 8)
		return (0);
	else
		return (2);
}

void	put_uint_base(t_info *info, uintmax_t n, char *base)
{
	if (n >= info->base)
		put_uint_base(info, n / info->base, base);
	addchar(info, base[n % info->base]);
}

void	uint_base(t_info *info, uintmax_t n)
{
	put_uint_base(info, n,
			(info->caps ? "0123456789ABCDEF" : "0123456789abcdef"));
}
