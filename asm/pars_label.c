/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:22:45 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/11 18:55:12 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	pars_label(char *str, t_label **lab)
{
	int		i;
	int		ret;
	char	*label;
	char	*opcode;

	i = 0;
	ret = 0;
	label = NULL;
	while (str[i] != LABEL_CHAR && str[i] != ' ' && str[i] != '\t' && str[i])
	{
		ret += label_chars(str[i], LABEL_CHARS);
		i++;
	}
	if (str[i] == '\0')
		error_syntax();
	if (str[i] == LABEL_CHAR)
	{
		if (ret)
			error_syntax();
		label = ft_strn_dup(str, i);
		del_seq(str, 0, i + 1);
		while (str[i] == ' ' || str[i] == '\t')
			del_pos(str, 0);
	}
	create_lab_lst(lab, label);
}
