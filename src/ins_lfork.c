/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_lfork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:01:13 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 14:32:00 by mschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ins_lfork(t_proc *process, t_data *data)
{
	int				position;
	t_proc			*new;

	if (!process->instruction_started)
	{
		process->time_to_wait = 1000 - 2;
		process->instruction_started = TRUE;
		return ;
	}
	position = mem_get_short_int(data, process, 1);
	new = (t_proc*)ealloc(sizeof(t_proc));
	proc_cpy(process, new);
	new->pc = process->pc + position;
	new->next = data->procs;
	data->procs = new;
	if (data->args->verbosity & V_OPERATIONS)
		ft_printf("P   %2i | lforked at position %i\n",
				process->champion_id, position);
	increment_pc(data, process, 3);
}
