/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:01:12 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 14:01:12 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** On parcourt toute la liste et on compte toutes les vies du cycle precedent
*/

int				count_all_lives(t_data *data)
{
	t_proc		*current;
	int			count;

	current = data->procs;
	count = 0;
	while (current != NULL)
	{
		count += current->live;
		current = current->next;
	}
	return (count);
}

/*
** On va verifier s'il y a eu des vies au cycle precedent,
** S'il n'y en a pas eu la partie s'arrete et on affiche le gagnant
** S'il y en a en revanche on va d'abord verifier si l'on doit decrementer
** CYCLE_TO_DIE, soit parce qu'on ne l'a pas fait depuis un moment soit
** parce qu'il y a eu plus de NBR_LIVE puis on va nettoyer les process morts
** qui n'ont pas fait de live pendant le dernier cycle.
*/

int				mem_check_alive(t_data *data)
{
	int			total_live_instructions;

	data->mem->since_last_check = -1;
	if (data->procs == NULL)
		return (0);
	total_live_instructions = count_all_lives(data);
	if (data->mem->checks_since_last_decrement == MAX_CHECKS
			|| total_live_instructions >= NBR_LIVE)
	{
		data->mem->cycle_to_die -= CYCLE_DELTA;
		data->mem->checks_since_last_decrement = 0;
	}
	else
		data->mem->checks_since_last_decrement += 1;
	if (total_live_instructions != 0)
		clean_dead_processes(data);
	else
		return (0);
	return (1);
}

/*
** Un grand classique, nettoyer une liste simplement chainee, on comence
** par nettoyer au debut pour mettre a jour la head puis on avance dans la
** liste et on "coupe" dedans les elements a enlever.
*/

void			clean_dead_processes(t_data *data)
{
	t_proc		*previous;
	t_proc		*current;

	while (data->procs != NULL && data->procs->live == 0)
	{
		previous = data->procs->next;
		free(data->procs);
		data->procs = previous;
	}
	if ((previous = data->procs) == NULL)
		return ;
	current = data->procs->next;
	while (current != NULL)
	{
		if (current->live == 0)
		{
			speak_kill(data);
			previous->next = current->next;
			free(current);
		}
		else
			previous = previous->next;
		current = previous->next;
	}
}
