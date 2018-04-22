/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_list_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:01:16 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 14:01:16 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_proc			*proc_new(int id, int starting_pos)
{
	t_proc	*new;

	new = ealloc(sizeof(t_proc));
	new->next = NULL;
	new->starting_pos = starting_pos;
	new->champion_id = id;
	new->live = 0;
	ft_bzero(new->registers, (REG_NUMBER + 1) * sizeof(int));
	new->registers[1] = 0xffffffff - id + 1;
	new->pc = 0;
	new->carry = 0;
	new->instruction_started = 0;
	new->time_to_wait = 0;
	new->proc_color = -1;
	return (new);
}

void			proc_list_add(t_data *data, t_proc *new)
{
	new->next = data->procs;
	data->procs = new;
}

void			print_proc_list(t_data *data)
{
	t_proc		*current;

	current = data->procs;
	while (current != NULL)
		current = current->next;
}

void			proc_list_free(t_proc *current)
{
	t_proc		*tmp;

	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
