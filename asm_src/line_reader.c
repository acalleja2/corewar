/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:28:31 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/18 19:42:32 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	line_reader(int fd, t_label **lab, t_instru **ins, char *file)
{
	char		*line;
	header_t	*head;

	head = (header_t *)ealloc(sizeof(header_t));
	line = NULL;
	check_header(line, fd, head);
	while (get_next_line(fd, &line) == 1)
	{
		str_replace(line, COMMENT_CHAR, '\0');
		str_replace(line, ';', '\0');
		while (line[0] == ' ' || line[0] == '\t')
			del_pos(line, 0);
		line_reader2(line, lab, ins);
		free(line);
	}
	check_param(*ins, *lab);
	put_lab_value(*ins);
	create_cor(file, *ins, head);
	free_instru(ins);
	free_lab(lab);
	free(head);
}

void	line_reader2(char *line, t_label **lab, t_instru **ins)
{
	t_instru	*tmp;

	if (line[0] != '\0')
	{
		pars_label(line, lab);
		if (line[0] != '\0')
		{
			create_instru_lst(ins);
			tmp = *ins;
			while (tmp->next)
				tmp = tmp->next;
			tmp->lab = *lab;
			pars_opcode(line, &tmp);
			pars_param(line, &tmp);
			*lab = NULL;
			if (!check_opcode(tmp))
				error_opcode(tmp->opcode);
			check_nb_param(tmp);
		}
	}
}
