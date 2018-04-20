/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:02:36 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/20 19:32:31 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_header(char *str, int fd, header_t *head)
{
	int		name;
	int		desc;
	int		i;
	int		ret;

	i = 0;
	name = 0;
	desc = 0;
	init_head(head);
	while ((ret = get_next_line(fd, &str)))
	{
		check_header2(str);
		if (str[0] != '\0')
		{
			if (!name)
				name = pars_name(&str, head, fd);
			if (!desc)
				desc = pars_desc(&str, head, fd);
			error_hd(name, desc, ++i);
		}
		free(str);
		if (name && desc)
			break ;
	}
	magic(ret, head);
}

void	init_head(header_t *head)
{
	ft_bzero(head->prog_name, PROG_NAME_LENGTH);
	ft_bzero(head->comment, COMMENT_LENGTH);
}

void	check_header2(char *str)
{
	while (str[0] == ' ' || str[0] == '\t')
		del_pos(str, 0);
	str_replace(str, COMMENT_CHAR, '\0');
	str_replace(str, ';', '\0');
}

void	magic(int ret, header_t *head)
{
	if (ret != 1)
		error_header();
	head->magic = COREWAR_EXEC_MAGIC;
}

void	error_hd(int name, int desc, int i)
{
	if (name + desc != i)
		error_header();
}
