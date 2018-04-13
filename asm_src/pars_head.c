/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_head.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:45:34 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/13 19:07:58 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		pars_name(char *str, header_t *head, int fd)
{
	int		i;
	char	*name;
	char	*nm;
	char	*tmp;
	char	buf[2];

	buf[1] = '\0';
	nm = ft_strnew(0);
	name = ft_strdup(NAME_CMD_STRING);
	i = 0;
	while (str[i] && name[i] && str[i] == name[i])
		i++;
	if (name[i] == '\0')
	{
		del_seq(str,0 ,i +1);
		i = 0;
		free(name);
		while (str[0] == ' ' || str[0] == '\t')
			del_pos(str, 0);
		if (str[0] == '"')
			del_pos(str, 0);
		while (str[i] != '"')
		{
			if (str[i] == '\0')
			{
				i = 0;
				if (get_next_line(fd, &str) < 1)
					error_header();
			}
			else
			{
				tmp = nm;
				buf[0] = str[i];
				nm = ft_strjoin(nm, buf);
				free(tmp);
				i++;
			}
		}
		if (ft_strlen(nm) <= PROG_NAME_LENGTH)
			ft_strcpy(head->prog_name, nm);
		else
			error_header();
		return (1);
	}
	return (0);
}

int		pars_desc(char *str, header_t *head, int fd)
{
	int		i;
	char	*name;
	char	*nm;
	char	*tmp;
	char	buf[2];

	buf[1] = '\0';
	nm = ft_strnew(0);
	name = ft_strdup(COMMENT_CMD_STRING);
	i = 0;
	while (str[i] && name[i] && str[i] == name[i])
		i++;
	if (name[i] == '\0')
	{
		del_seq(str,0 ,i +1);
		i = 0;
		free(name);
		while (str[0] == ' ' || str[0] == '\t')
			del_pos(str, 0);
		if (str[0] == '"')
			del_pos(str, 0);
		while (str[i] != '"')
		{
			if (str[i] == '\0')
			{
				i = 0;
				if (get_next_line(fd, &str) < 1)
					error_header();
			}
			else
			{
				tmp = nm;
				buf[0] = str[i];
				nm = ft_strjoin(nm, buf);
				free(tmp);
				i++;
			}
		}
		if (ft_strlen(nm) <= COMMENT_LENGTH)
			ft_strcpy(head->comment, nm);
		else
			error_header();
		return (1);
	}
	return (0);
}
