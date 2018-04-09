/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:03:37 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/18 19:03:37 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		norm_error(char *buffer)
{
	free(buffer);
	return (-1);
}

static int		read_more(const int fd, char **data, char sep)
{
	char		*buffer;
	char		*tmp;
	int			read_res;
	int			did_we_read;

	if (!(buffer = (char*)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	did_we_read = 0;
	read_res = -1;
	while (!ft_strchr(buffer, sep) &&
			(read_res = (int)read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[read_res] = '\0';
		tmp = *data;
		if (!(*data = ft_str_add(*data, buffer)))
			return (norm_error(buffer));
		free(tmp);
		did_we_read = 1;
	}
	free(buffer);
	if (read_res < 0)
		return (-1);
	return (did_we_read);
}

static int		check_last(char **data, char **line)
{
	if (!(*data))
		return (0);
	if (**data == '\0')
	{
		ft_strdel(data);
		return (0);
	}
	if ((*line = ft_strdup(*data)) == NULL)
		return (-1);
	ft_strdel(data);
	return (1);
}

int				get_next_line_char(const int fd, char **line, char sep)
{
	static char	*data;
	char		*nl;
	char		*tmp;

	if (fd < 0)
		return (-1);
	if (data == NULL || (nl = ft_strchr(data, sep)) == NULL)
		if (read_more(fd, &data, sep) < 0)
			return (-1);
	nl = ft_strchr(data, sep);
	if (!nl)
		return (check_last(&data, line));
	*nl = '\0';
	if (line == NULL || !(*line = ft_strdup(data)))
		return (-1);
	tmp = data;
	if (!(data = ft_strdup(nl + 1)))
		return (-1);
	free(tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	return (get_next_line_char(fd, line, '\n'));
}
