/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:01:14 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 14:01:14 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Here the magic happens
*/

void			mem_load(t_mem *mem, t_champion *current, int starting_pos)
{
	int			i;

	i = 0;
	while (i < current->bytes)
	{
		mem_setup_byte(mem, current->code[i], starting_pos + i, current->id);
		i += 1;
	}
}

void			add_process(t_data *data, t_champion *current, int starting_pos)
{
	proc_list_add(data, proc_new(current->id, starting_pos));
	mem_load(data->mem, current, starting_pos);
}

void			load_champs_and_setup_processes(t_data *data)
{
	int				starting_pos;
	t_champion		*current;

	starting_pos = 0;
	current = data->champs;
	while (current != NULL)
	{
		add_process(data, current, starting_pos);
		current = current->next;
		starting_pos += MEM_SIZE / data->args->champ_number;
	}
}
