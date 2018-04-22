/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_zjmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:01:14 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 14:01:14 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ins_zjmp(t_proc *process, t_data *data)
{
	int		p;

	if (!process->instruction_started)
	{
		process->time_to_wait = 20 - 2;
		process->instruction_started = TRUE;
		return ;
	}
	process->instruction_started = FALSE;
	if (process->carry)
	{
		p = mem_get_short_int(data, process, 1);
		process->pc += p;
		if (data->args->verbosity & V_OPERATIONS)
			ft_printf("P   %2i | zjmp %i OK\n", process->champion_id, p);
	}
	else
		increment_pc(data, process, 3);
}
