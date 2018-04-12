/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:28:31 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/12 20:33:44 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	line_reader(int fd, t_label **lab, t_instru **ins)
{
	char		*line;
	t_instru	*tmp;

	while (get_next_line(fd, &line) == 1)
	{
		str_replace(line, COMMENT_CHAR, '\0');
		str_replace(line, ';', '\0');
		while (line[0] == ' ' || line[0] == '\t')
			del_pos(line, 0);
		if (line[0] == '\0')
			free(line);
		else
		{
			pars_label(line, lab);
			if (line[0] == '\0')
				free(line);
			else
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
			}
		}
	}
	print_ins(*ins);
}
