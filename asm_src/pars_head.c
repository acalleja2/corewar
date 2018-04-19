/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_head.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:45:34 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/19 17:49:13 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		pars_name(char **str, header_t *head, int fd)
{
	int		i;
	char	*name;
	char	*nm;

	nm = NULL;
	name = ft_strdup(NAME_CMD_STRING);
	i = 0;
	while ((*str)[i] && name[i] && (*str)[i] == name[i])
		i++;
	if (name[i] == '\0')
	{
		pars_nm_dc(*str, i, name);
		nm = pars_nm(str, 0, fd);
		if (ft_strlen(nm) <= PROG_NAME_LENGTH)
			ft_strcpy(head->prog_name, nm);
		else
			error_header();
		free(nm);
		return (1);
	}
	if (nm)
		free(nm);
	free(name);
	return (0);
}

char	*pars_nm(char **str, int i, int fd)
{
	char	buf[2];
	char	*tmp;
	char	*nm;

	nm = ft_strnew(0);
	buf[1] = '\0';
	while ((*str)[i] != '"')
	{
		if ((*str)[i] == '\0')
		{
			i = 0;
			free(*str);
			if (get_next_line(fd, str) < 1)
				error_header();
		}
		else
		{
			tmp = nm;
			buf[0] = (*str)[i];
			nm = ft_strjoin(nm, buf);
			free(tmp);
			i++;
		}
	}
	return (nm);
}

char	*pars_dc(char **str, int i, int fd)
{
	char	buf[2];
	char	*tmp;
	char	*nm;

	nm = ft_strnew(0);
	buf[1] = '\0';
	while ((*str)[i] != '"')
	{
		if ((*str)[i] == '\0')
		{
			i = 0;
			free(*str);
			if (get_next_line(fd, str) < 1)
				error_header();
		}
		else
		{
			tmp = nm;
			buf[0] = (*str)[i];
			nm = ft_strjoin(nm, buf);
			free(tmp);
			i++;
		}
	}
	return (nm);
}

void	pars_nm_dc(char *str, int i, char *name)
{
	del_seq(str, 0, i + 1);
	free(name);
	while (str[0] == ' ' || str[0] == '\t')
		del_pos(str, 0);
	if (str[0] == '"')
		del_pos(str, 0);
	else
		error_header();
}

int		pars_desc(char **str, header_t *head, int fd)
{
	int		i;
	char	*name;
	char	*nm;

	nm = NULL;
	name = ft_strdup(COMMENT_CMD_STRING);
	i = 0;
	while ((*str)[i] && name[i] && (*str)[i] == name[i])
		i++;
	if (name[i] == '\0')
	{
		pars_nm_dc(*str, i, name);
		nm = pars_dc(str, 0, fd);
		if (ft_strlen(nm) <= COMMENT_LENGTH)
			ft_strcpy(head->comment, nm);
		else
			error_header();
		free(nm);
		return (1);
	}
	if (nm)
		free(nm);
	free(name);
	return (0);
}
