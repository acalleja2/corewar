/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:51:15 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 14:19:04 by mschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Tout d'abord on verifie si le process est "gele" c'est-a-dire qu'il
** est sur un opcode qu'il a demarre. Si c'est le cas on diminue son
** temps d'attente. S'il n'a pas de temps d'attente c'est qu'il est
** disponible. On va alors executer l'instruction correspondant a
** l'octet sur lequel il se trouve.
*/

void			process_exec(t_data *data, t_proc *process)
{
	unsigned char		instruction;

	if (process->time_to_wait > 0)
	{
		process->time_to_wait -= 1;
		return ;
	}
	instruction = mem_get_byte(data, process, 0);
	switch_instruction(process, instruction, data);
}

/*
** Au cours du cycle on parcourt toute la liste des process
** et on execute les instructions pour chaque
*/

void			exec_cycle(t_data *data)
{
	t_proc		*current;

	current = data->procs;
	while (current != NULL)
	{
		process_exec(data, current);
		current = current->next;
	}
}

/*
** A chaque cycle on va executer tous les process et verifier s'il en reste en
** vie. Des qu'ils sont tous morts on affiche le gagnant.
*/

void			vm_loop(t_data *data)
{
	WINDOW		*map;

	map = init_ncurse(data);
	while (42)
	{
		print_cycle_start_vm_lopp(data);
		if (data->args->ncurses != -1)
			if (!ncurses_main_loop(map, data))
				break ;
		exec_cycle(data);
		if (data->mem->since_last_check == data->mem->cycle_to_die
				&& (!mem_check_alive(data) || data->mem->cycle_to_die <= 0))
		{
			if (data->args->ncurses == -1)
				ft_printf("The game ended after %i cycles :\n",
						data->mem->cycle);
			print_winner(data, map);
			return ;
		}
		data->mem->since_last_check += 1;
		print_cycle_end_vm_loop(data);
		if (data->mem->cycle == data->args->dump)
		{
			print_mem(data->mem);
			return ;
		}
		data->mem->cycle += 1;
	}
	end_ncurses(map);
}

/*
** TODO rajouter une option pour le mode arc-en-ciel.
*/

void			print_cycle_start(t_data *data)
{
	static char	buf[6] = "\e[30m";

	buf[3] = 49 + data->mem->cycle % 6;
	if (data->args->rainbow)
		ft_printf("It is now cycle %s%i\n", buf, data->mem->cycle);
	else
		ft_printf("It is now cycle %i\n", data->mem->cycle);
}

void			print_cycle_end(t_data *data)
{
	if (data->args->rainbow)
		ft_printf(CLEAR);
}
