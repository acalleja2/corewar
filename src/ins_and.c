/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:01:13 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 14:01:13 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Effectue un AND (&) entre les deux parametres et stocke le resultat dans le
** troisieme.
** Si le resultat est nul passe le carry a un, sinon le passe a 0
*/

void		ins_and(t_proc *process, t_data *data)
{
	int				p1;
	int				p2;
	int				p3;
	int				offset;

	if (!process->instruction_started)
	{
		process->time_to_wait = 6 - 2;
		process->instruction_started = TRUE;
		return ;
	}
	process->instruction_started = FALSE;
	offset = get_ocp_3_direct_params(data, process, &p1, &p2, &p3);
	if (is_first_param_register(data, process))
		p1 = get_nth_register_value(process, p1);
	if (is_second_param_register(data, process))
		p2 = get_nth_register_value(process, p2);
	set_nth_register_value(process, p3, p1 & p2);
	process->carry = !(p1 & p2);
	if (data->args->verbosity & V_OPERATIONS)
		ft_printf("P   %2i | and %i %i (= %i) r%i\n",
				process->champion_id, p1, p2, p1 & p2, p3);
	increment_pc(data, process, offset);
}
