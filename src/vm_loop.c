#include "corewar.h"

void			process_exec(t_mem *mem, t_proc *process, t_champion *champs)
{
	unsigned char		instruction;

	if (process->time_to_wait > 0)
	{
		process->time_to_wait -= 1;
		return ;
	}
	instruction = mem_get_byte(mem, process, 0);
	switch_instruction(mem, process, champs, instruction);
}

void			exec_cycle(t_mem *mem, t_champion *champs)
{
	t_proc		*current;

	current = mem->first;
	while (current != NULL)
	{
		process_exec(mem, current, champs);
		current = current->next;
	}
}

void			vm_loop(t_mem *mem, t_champion *champs, t_args *args)
{
	while (42)
	{
		exec_cycle(mem, champs);
		if (mem->since_last_check == mem->cycle_to_die)
			if (!mem_check_alive(mem, champs))
			{
				ft_printf("We got a winner after %i cycles :\n", mem->cycle);
				print_winner(champs, args);
				break ;
			}
		mem->cycle += 1;
		mem->since_last_check += 1;
	}
}
