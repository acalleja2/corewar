/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:27:59 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/02 15:31:36 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				ft_dprintf(int fd, const char *format, ...)
{
	va_list		args;
	int			return_value;
	t_out		out;

	out.fd = fd;
	out.buffer = NULL;
	va_start(args, format);
	return_value = printf_core(&out, 0, format, args);
	va_end(args);
	return (return_value);
}

int				ft_dnprintf(int fd, size_t max, const char *format, ...)
{
	va_list		args;
	int			return_value;
	t_out		out;

	if (!max)
		return (0);
	out.fd = fd;
	out.buffer = NULL;
	va_start(args, format);
	return_value = printf_core(&out, max, format, args);
	va_end(args);
	return (return_value);
}

int				ft_vdprintf(int fd, const char *format, va_list args)
{
	t_out		out;

	out.fd = fd;
	out.buffer = NULL;
	return (printf_core(&out, 0, format, args));
}

int				ft_vdnprintf(int fd,
							size_t max, const char *format, va_list args)
{
	t_out		out;

	if (!max)
		return (0);
	out.fd = fd;
	out.buffer = NULL;
	return (printf_core(&out, max, format, args));
}
