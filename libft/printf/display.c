/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:33:06 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/02 17:01:48 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		init(t_out *out, size_t max, t_info *info, char **format)
{
	if (out->buffer)
	{
		info->show = &add_buffer;
		add_buffer(INIT, out, NULL, '\0');
	}
	else
	{
		info->show = &add_fd;
		add_fd(INIT, out, NULL, '\0');
	}
	info->max = max;
	info->fmt = format;
	info->total = 0;
}

void		add_buffer(int flag, t_out *out, t_info *info, char c)
{
	static size_t	pos;
	static char		*buff;

	(void)info;
	if (flag == INIT)
	{
		pos = 0;
		buff = out->buffer;
	}
	else if (flag == FLUSH)
	{
		buff[pos] = '\0';
	}
	else
	{
		buff[pos] = c;
		pos += 1;
	}
}

void		add_fd(int flag, t_out *out, t_info *info, char c)
{
	static int		fd;
	static size_t	pos;
	static char		buff[PRINTF_BUFF_SIZE];

	(void)info;
	if (flag == INIT)
	{
		fd = out->fd;
		pos = 0;
	}
	else if (flag == FLUSH)
		write(fd, buff, pos);
	else
	{
		buff[pos] = c;
		pos += 1;
		if (pos == PRINTF_BUFF_SIZE)
		{
			write(fd, buff, PRINTF_BUFF_SIZE);
			pos = 0;
		}
	}
}

void		flush(t_out *out, t_info *info)
{
	if (out->buffer)
		add_buffer(FLUSH, NULL, info, 0);
	else
		add_fd(FLUSH, NULL, info, 0);
}
