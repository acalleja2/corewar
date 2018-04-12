/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:28:31 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/11 19:36:43 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	line_reader(int fd, t_label **lab, t_instru **ins)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		while (line[0] == ' ' || line[0] == '\t')
			del_pos(line, 0);
		if (line[0] == '\0' || line[0] == COMMENT_CHAR)
			free(line);
		else
		{
			pars_label(line, lab);
			if (line[0] == '\0' || line[0] == COMMENT_CHAR)
				free(line);
			else
			{
				pars_opcode(line, ins);
				pars_param(line, ins);
			}
		}
	}
}
