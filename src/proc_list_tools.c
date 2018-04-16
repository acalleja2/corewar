#include "corewar.h"

t_proc		*proc_new(int id, int starting_pos)
{
	t_proc	*new;

	new = ealloc(sizeof(t_proc));
	new->next = NULL;
	new->starting_pos = starting_pos;
	new->champion_id = id;
	new->live = 0;
	ft_bzero(new->registers, (REG_NUMBER + 1) * sizeof(int));
	new->registers[1] = 0xffffffff - id + 1;
	new->pc = 0;
	new->carry = 0;
	new->instruction_started = 0;
	new->time_to_wait = 0;
	return (new);
}

void			proc_list_add(t_data *data, t_proc *new)
{
	new->next = data->procs;
	data->procs = new;
}

void			print_proc_list(t_data *data)
{
	t_proc		*current;

	ft_printf("Printing process list :\n");
	current = data->procs;
	while (current != NULL)
	{
		ft_printf("Process id %i has his origin at %i\n",
				current->champion_id, current->starting_pos);
		current = current->next;
	}
}

void			proc_list_free(t_proc *current)
{
	t_proc		*tmp;

	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
