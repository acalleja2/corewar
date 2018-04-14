#include "corewar.h"

void			vm_loop(t_mem *mem, t_champion *champs)
{
	while (42)
	{
		/* exec_cycle(mem); */
		if (mem->since_last_check == mem->cycle_to_die)
			if (!mem_check_alive(mem))
			{
				print_winner(mem, champs);
				break ;
			}
	}
}
