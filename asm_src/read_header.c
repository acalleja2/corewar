/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:02:36 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/16 13:03:52 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_header(char *str, int fd, header_t *head)
{
	int		name;
	int		desc;
	int		i;

	i = 0;
	name = 0;
	desc = 0;
	ft_bzero(head->prog_name, PROG_NAME_LENGTH);
	ft_bzero(head->comment, COMMENT_LENGTH);
	while (get_next_line(fd, &str))
	{
		while (str[0] == ' ' || str[0] == '\t')
			del_pos(str, 0);
		str_replace(str, COMMENT_CHAR, '\0');
		str_replace(str, ';', '\0');
		if (str[0] == '\0')
			free(str); 
		else
		{
			if (!name)
				name = pars_name(str, head, fd);
			if (!desc)
				desc = pars_desc(str, head, fd);
			i++;
			if (name + desc != i)
				error_header();
		}
		if (name && desc)
			break ;
	}
	if (!head->prog_name[0] || !head->comment[0])
		error_header();
	head->magic = 0xea83f3;
}
