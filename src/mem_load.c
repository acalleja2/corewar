#include "corewar.h"

/*
** Here the magic happens
*/

void			mem_load(t_mem *mem, t_champion *current, int starting_pos)
{
	int			i;

	i = 0;
	while (i < current->bytes)
	{
		mem_set_byte(mem, current->code[i], starting_pos + i, current->id);
		i += 1;
	}
}

void			add_process(t_mem *mem, t_champion *current, int starting_pos)
{
	proc_list_add(mem, proc_new(current->id, starting_pos));
	mem_load(mem, current, starting_pos);
}

void			load_champs_and_setup_processes(t_args *args, t_champion **champs, t_mem *mem)
{
	int				starting_pos;
	t_champion		*current;

	starting_pos = 0;
	current = *champs;
	while (current != NULL)
	{
		add_process(mem, current, starting_pos);
		current = current->next;
		starting_pos += MEM_SIZE / args->champ_number;
	}
}
