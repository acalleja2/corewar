#include "corewar.h"

/*
** Prend un direct en parametre et spawn un nouveau process a cet endroit
*/

void		proc_cpy(t_proc *parent, t_proc *child)
{
	child->starting_pos = parent->starting_pos;
	child->champion_id = parent->champion_id;
	child->live = parent->live;
	child->time_to_wait = 0;
	child->instruction_started = FALSE;
	ft_memcpy(child->registers, parent->registers, 
			sizeof(int) * (REG_NUMBER + 1));
	child->carry = parent->carry;
}

void		ins_fork(t_proc *process, t_data *data)
{
	t_proc			*new;
	int				position;

	if (!process->instruction_started)
	{
		process->time_to_wait = 800 - 2;
		process->instruction_started = TRUE;
		return ;
	}
	process->instruction_started = FALSE;
	position = mem_get_short_int(data, process, 1);
	new = (t_proc*)ealloc(sizeof(t_proc));
	proc_cpy(process, new);
	new->pc = process->pc + position;
	new->next = data->procs;
	data->procs = new;
	if (data->args->verbosity & V_OPERATIONS)
		ft_printf("P   %2i | fork %i\n", process->champion_id, position);
	increment_pc(data, process, 3);
}
