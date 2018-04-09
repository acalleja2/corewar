/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:19:48 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/02 15:27:35 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				ft_sprintf(char *buffer, const char *format, ...)
{
	va_list		args;
	int			return_value;
	t_out		out;

	if (!buffer || !format)
		return (-1);
	out.fd = 0;
	out.buffer = buffer;
	va_start(args, format);
	return_value = printf_core(&out, 0, format, args);
	va_end(args);
	return (return_value);
}

int				ft_snprintf(char *buffer, size_t max, const char *format, ...)
{
	va_list		args;
	int			return_value;
	t_out		out;

	if (!format || !buffer)
		return (-1);
	if (!max)
		return (0);
	if (max == 1)
	{
		buffer[0] = '\0';
		return (1);
	}
	out.fd = 0;
	out.buffer = buffer;
	va_start(args, format);
	return_value = printf_core(&out, max - 1, format, args);
	va_end(args);
	return (return_value);
}

int				ft_vsprintf(char *buffer, const char *format, va_list args)
{
	t_out		out;

	if (!buffer || !format)
		return (-1);
	out.fd = 0;
	out.buffer = buffer;
	return (printf_core(&out, 0, format, args));
}

int				ft_vsnprintf(char *buffer,
							size_t max, const char *format, va_list args)
{
	t_out		out;

	if (!format || !buffer)
		return (-1);
	if (!max)
		return (0);
	if (max == 1)
	{
		buffer[0] = '\0';
		return (1);
	}
	out.fd = 0;
	out.buffer = buffer;
	return (printf_core(&out, max - 1, format, args));
}
