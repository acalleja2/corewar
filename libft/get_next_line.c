/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:12:47 by acalleja          #+#    #+#             */
/*   Updated: 2018/03/23 01:26:39 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd	*search_fd(t_fd *list, int fd)
{
	while (list)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	return (NULL);
}

t_fd	*create_list(t_fd *list, int fd)
{
	t_fd *begin;
	t_fd *new;

	begin = list;
	if (!list)
	{
		new = (t_fd *)malloc(sizeof(t_fd));
		new->fd = fd;
		new->cpy = NULL;
		new->next = NULL;
		return (new);
	}
	while (list)
	{
		if (list->fd == fd)
			return (begin);
		list = list->next;
	}
	new = (t_fd *)malloc(sizeof(t_fd));
	new->fd = fd;
	new->cpy = NULL;
	new->next = begin;
	return (new);
}

size_t	check(char *str, t_fd *tmp, char **line, int n)
{
	size_t i;

	i = 0;
	if (n == 0)
	{
		while (str[i])
		{
			if (str[i] == '\n' || str[i] == EOF)
				return (i);
			i++;
		}
		return (i);
	}
	if (ft_strlen(tmp->cpy) != 0)
	{
		*line = ft_strndup(tmp->cpy, ft_strlen(tmp->cpy));
		tmp->cpy = NULL;
		return (1);
	}
	return (0);
}

int		reader_fd(t_fd *tmp, char **line, int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*t;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		t = tmp->cpy;
		tmp->cpy = ft_strjoin(tmp->cpy, buf);
		free(t);
		if (check(tmp->cpy, tmp, line, 0) != ft_strlen(tmp->cpy))
		{
			*line = ft_strndup(tmp->cpy, check(tmp->cpy, tmp, line, 0));
			t = tmp->cpy;
			tmp->cpy = ft_realloc(tmp->cpy, check(tmp->cpy, tmp, line, 0) + 1);
			free(t);
			return (1);
		}
	}
	if (check(tmp->cpy, tmp, line, 1) == 1)
		return (1);
	if (ret < 0)
		return (-1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_fd		*list = NULL;
	t_fd			*tmp;
	char			buf[1];

	if (read(fd, buf, 0) < 0)
		return (-1);
	list = create_list(list, fd);
	tmp = search_fd(list, fd);
	if (fd < 0)
		return (-1);
	if (!tmp->cpy)
		tmp->cpy = ft_strnew(0);
	if (check(tmp->cpy, tmp, line, 0) < ft_strlen(tmp->cpy))
	{
		*line = ft_strndup(tmp->cpy, check(tmp->cpy, tmp, line, 0));
		tmp->cpy = ft_realloc(tmp->cpy, check(tmp->cpy, tmp, line, 0) + 1);
		return (1);
	}
	return (reader_fd(tmp, line, fd));
}
