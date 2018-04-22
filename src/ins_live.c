/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_live.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:01:13 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 14:01:13 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ins_live(t_proc *process, t_data *data)
{
	int				id;
	t_champion		*champion;

	if (!process->instruction_started)
	{
		process->time_to_wait = 10 - 2;
		process->instruction_started = TRUE;
		return ;
	}
	process->instruction_started = FALSE;
	process->live += 1;
	id = mem_get_int(data, process, 1);
	champion = get_champion_by_id(data->champs, id);
	if (champion != NULL)
		champion->last_seen_alive = data->mem->cycle;
	if (data->args->verbosity & V_OPERATIONS)
		ft_printf("P   %2i | live %i\n", process->champion_id, id);
	if ((data->args->verbosity & V_LIVES) && champion != NULL)
		ft_printf("A process claimed a live for player %i (%s)\n",
				champion->id, champion->name);
	increment_pc(data, process, 5);
}
