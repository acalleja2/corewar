/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_lld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:01:13 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 14:01:13 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ins_lld(t_proc *process, t_data *data)
{
	int				p1;
	int				p2;
	int				offset;

	if (!process->instruction_started)
	{
		process->time_to_wait = 10 - 2;
		process->instruction_started = TRUE;
		return ;
	}
	process->instruction_started = FALSE;
	offset = get_ocp_2_direct_params(data, process, &p1, &p2);
	set_nth_register_value(process, p2, p1);
	process->carry = !(p1);
	if (data->args->verbosity & V_OPERATIONS)
		ft_printf("P   %2i | lld r%i %i\n"
				"       | -> store %i to %i\n",
				process->champion_id, p1, p2,
				get_nth_register_value(process, p2), p2);
	increment_pc(data, process, offset);
}
