#include "corewar.h"

/*
** On parcourt toute la liste et on compte toutes les vies du cycle precedent
*/

int				count_all_lives(t_mem *mem)
{
	t_proc		*current;
	int			count;

	current = mem->first;
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

int				mem_check_alive(t_mem *mem, t_champion *champs)
{
	int			total_live_instructions;

	mem->since_last_check = -1;
	if (mem->first == NULL)
		return (0);
	total_live_instructions = count_all_lives(mem);
	if (mem->checks_since_last_decrement == MAX_CHECKS
			|| total_live_instructions >= NBR_LIVE)
	{
		mem->cycle_to_die -= CYCLE_DELTA;
		mem->checks_since_last_decrement = 0;
	}
	else
		mem->checks_since_last_decrement += 1;
	if (total_live_instructions != 0)
		clean_dead_processes(mem);
	else
		return (0);
	return (1);
}

/*
** Un grand classique, nettoyer une liste simplement chainee, on comence
** par nettoyer au debut pour mettre a jour la head puis on avance dans la
** liste et on "coupe" dedans les elements a enlever.
*/

void			clean_dead_processes(t_mem *mem)
{
	t_proc		*previous;
	t_proc		*current;

	while (mem->first != NULL && mem->first->live == 0)
	{
		previous = mem->first->next;
		free(mem->first);
		mem->first = previous;
	}
	if ((previous = mem->first) == NULL)
		return ;
	current = mem->first->next;
	while (current != NULL)
	{
		if (current->live == 0)
		{
			previous->next = current->next;
			free(current);
			if (previous->next == NULL)
				return ;
		}
		previous = previous->next;
		current = previous->next;
	}
}
