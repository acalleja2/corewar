/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_ldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:01:13 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 14:01:13 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ins_ldi(t_proc *process, t_data *data)
{
	int				p1;
	int				p2;
	int				p3;
	int				offset;

	if (!process->instruction_started)
	{
		process->time_to_wait = 25 - 2;
		process->instruction_started = TRUE;
		return ;
	}
	process->instruction_started = FALSE;
	offset = get_ocp_3_indirect_params(data, process, &p1, &p2, &p3);
	set_nth_register_value(process, p3, mem_get_byte(data, process, p1 + p2));
	process->carry =  !mem_get_byte(data, process, p1 + p2);
	if (data->args->verbosity & V_OPERATIONS)
		ft_printf("P   %2i | ldi %i + %i in %i\n", 
				process->champion_id, p1, p2, p3);
	increment_pc(data, process, offset);
}
