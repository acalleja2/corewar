#include "corewar.h"

t_proc		*proc_new(int id, int starting_pos)
{
	t_proc	*new;

	new = ealloc(sizeof(t_proc));
	new->next = NULL;
	new->starting_pos = starting_pos;
	new->champion_id = id;
	new->alive = 0;
	new->registers[0] = id;
	new->pc = 0;
	new->carry = 0;
	return (new);
}

void			proc_list_add(t_mem *mem, t_proc *new)
{
	new->next = mem->first;
	mem->first = new;
}

void			print_proc_list(t_mem *mem)
{
	t_proc		*current;

	ft_printf("Printing process list :\n");
	current = mem->first;
	while (current != NULL)
	{
		ft_printf("Process id %i has his origin at %i\n",
				current->champion_id, current->starting_pos);
		current = current->next;
	}
}
