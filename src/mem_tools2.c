/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_tools2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:31:39 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 14:31:39 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Recupere un int depuis la memoire et renvoie sa valeur avec le bon endianisme.
*/

int				mem_get_int(t_data *data, t_proc *process, int offset)
{

	unsigned char	tmp[4];

	tmp[0] = mem_get_byte(data, process, offset + 3);
	tmp[1] = mem_get_byte(data, process, offset + 2);
	tmp[2] = mem_get_byte(data, process, offset + 1);
	tmp[3] = mem_get_byte(data, process, offset + 0);
	return (*(int*)tmp);
}

/*
** Bon la c'est comme au-dessus mais ca renvoie un short.
*/

int				mem_get_short_int(t_data *data, t_proc *process, int offset)
{

	unsigned char	tmp[2];

	tmp[0] = mem_get_byte(data, process, offset + 1);
	tmp[1] = mem_get_byte(data, process, offset + 0);
	return ((int)(*(short int*)tmp));
}

/*
** Ici on set un int (4 octets de la VM). Tout comme au dessus on change
** l'endianisme avant de l'ecrire.
*/

void			mem_set_int(t_data *data, t_proc *process, int offset, int value)
{
	mem_set_byte(data, process, offset, (unsigned char)((value >> 24) & 0xff));
	mem_set_byte(data, process, offset + 1, (unsigned char)((value >> 16) & 0xff));
	mem_set_byte(data, process, offset + 2, (unsigned char)((value >> 8) & 0xff));
	mem_set_byte(data, process, offset + 3, (unsigned char)(value & 0xff));
}
