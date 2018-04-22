/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loop_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:09:38 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 15:09:38 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		print_cycle_start_vm_loop(t_data *data)
{
	if (data->args->verbosity & V_CYCLES)
		print_cycle_start(data);
}

void		print_cycle_end_vm_loop(t_data *data)
{
	if (data->args->verbosity & V_CYCLES)
		print_cycle_end(data);
}

void		print_end_game_vm_loop(t_data *data, WINDOW *map)
{
	if (data->args->ncurses == -1)
		ft_printf("The game ended after %i cycles :\n",
				data->mem->cycle);
	print_winner(data, map);
}

void		poubelle(t_data *data)
{
	data->mem->since_last_check += 1;
	print_cycle_end_vm_loop(data);
}
