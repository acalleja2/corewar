#include "corewar.h"

void			exec_cycle(t_mem *mem, t_champion *champs)
{
	t_proc		*current;

	current = mem->first;
	while (current != NULL)
	{
		/* process_exec(mem, current, champs); */
		current = current->next;
	}
}

void			vm_loop(t_mem *mem, t_champion *champs)
{
	while (42)
	{
		/* exec_cycle(mem, champs); */
		if (mem->since_last_check == mem->cycle_to_die)
			if (!mem_check_alive(mem, champs))
			{
				/* print_winner(champs); */
				break ;
			}
		mem->cycle += 1;
		mem->since_last_check += 1;
	}
}
