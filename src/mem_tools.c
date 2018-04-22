/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:01:14 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 14:01:14 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Fonction "legacy" d'avant la refactorisation, ne vous en servez pas.
** elle sert de wrapper pour mem_set_byte et lors du chargement des programmes
** en memoire.
*/

void			mem_setup_byte(t_mem *mem, unsigned char const byte,
		int const pos, int const id)
{
	int result;

	result = pos >= 0 ? pos % MEM_SIZE : MEM_SIZE + pos % MEM_SIZE;
	mem->map[result] = byte;
	mem->owner[result] = id;
}

/*
** Cette fonction permet a un process de set un octet situe offset octets apres
** son emplacement logique.
** map->owner est mis a jour par la meme occasion afin d'avoir les bonnes
** couleurs.
*/

void			mem_set_byte(t_data *data, t_proc *process, int offset,
		unsigned char value)
{
	mem_setup_byte(data->mem,
			value,
			process->starting_pos + process->pc + offset,
			process->champion_id);
}

/*
** Renvoie la valeur de l'octet pos octets apres l'emplacement logique du
** process.
** J'appelle "emplacement logique" la position de depart du process + son pc.
** Comme il se peut que le PC soit tres eleve on n'oublie pas le petit modulo.
*/

unsigned char	mem_get_byte(t_data *data, t_proc *process, int pos)
{
	return (data->mem->map[(process->starting_pos + process->pc + pos)
			% MEM_SIZE]);
}

/*
** Dump la memoire comme au format de la VM.
** Pour optimiser on cree un buffer et on fait un seul write.
** Pour comprendre comment ca marche : man 3 printf (lol)
*/

void			print_mem(t_mem *mem)
{
	int			row;
	int			col;
	int			offset;
	char		buffer[MEM_SIZE * 4 + 100];

	row = 0;
	offset = 0;
	while (row * 64 < MEM_SIZE)
	{
		offset += ft_sprintf(buffer + offset, "%#.4x : ", row * 64);
		col = 0;
		while (col < 64 && row * 64 + col < MEM_SIZE)
		{
			offset += ft_sprintf(buffer + offset, "%.2x ", mem->map[row * 64 + col]);
			col += 1;
		}
		buffer[offset] = '\n';
		offset += 1;
		row += 1;
	}
	write(1, buffer, offset);
}
