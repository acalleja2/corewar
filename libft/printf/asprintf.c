/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:10:09 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/24 11:10:09 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				ft_asprintf(char **strptr, const char *fmt, ...)
{
	va_list		args;
	int			tmp;

	va_start(args, fmt);
	tmp = ft_vasprintf(strptr, fmt, args);
	va_end(args);
	return (tmp);
}

/*
** C'est horriblement sale mais je voulais gratter les bonus
** Je la recoderai si vous en avez besoin
*/

int				ft_vasprintf(char **strptr, const char *fmt, va_list args)
{
	va_list		*argscpy;
	char		buffer[4];
	char		*new;
	int			tmp;

	if (strptr == NULL)
		return (-1);
	if ((argscpy = ealloc(sizeof(va_list))) == NULL)
		return (-1);
	(void)ft_memmove(argscpy, args, sizeof(va_list));
	tmp = ft_vsnprintf(buffer, 4, fmt, args);
	if (tmp == -1 || !(new = (char*)ealloc((tmp + 1) * sizeof(char))))
	{
		free(argscpy);
		return (-1);
	}
	if ((tmp = ft_vsnprintf(new, tmp + 1, fmt, *argscpy)) == -1)
	{
		free(argscpy);
		free(new);
		return (-1);
	}
	free(argscpy);
	*strptr = new;
	return (tmp);
}
