/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:30:51 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/02 15:31:33 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		args;
	int			return_value;
	t_out		out;

	out.fd = 1;
	out.buffer = NULL;
	va_start(args, format);
	return_value = printf_core(&out, 0, format, args);
	va_end(args);
	return (return_value);
}

int				ft_nprintf(size_t max, const char *format, ...)
{
	va_list		args;
	int			return_value;
	t_out		out;

	if (!max)
		return (0);
	out.fd = 1;
	out.buffer = NULL;
	va_start(args, format);
	return_value = printf_core(&out, max, format, args);
	va_end(args);
	return (return_value);
}

int				ft_vprintf(const char *format, va_list args)
{
	t_out		out;

	out.fd = 1;
	out.buffer = NULL;
	return (printf_core(&out, 0, format, args));
}

int				ft_vnprintf(size_t max, const char *format, va_list args)
{
	t_out		out;

	if (!max)
		return (0);
	out.fd = 1;
	out.buffer = NULL;
	return (printf_core(&out, max, format, args));
}
