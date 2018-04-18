#include "corewar.h"

void		proc_cpy(t_proc *parent, t_proc *child)
{
	child->starting_pos = parent->starting_pos;
	child->champion_id = parent->champion_id;
	child->live = parent->live;
	child->time_to_wait = parent->time_to_wait;
	child->instruction_started = parent->instruction_started;
	ft_memcpy(child->registers, parent->registers, 
			sizeof(int) * (REG_NUMBER + 1));
	child->carry = parent->carry;
}

void		ins_fork(t_proc *process, t_data *data)
{
	t_proc	*new;
	if (!process->instruction_started)
	{
		process->time_to_wait = 800 - 2;
		process->instruction_started = TRUE;
		return ;
	}
	new = (t_proc*)ealloc(sizeof(t_proc));
	proc_cpy(process, new);
	/*
	 * changer le pc de new, puis l'inserer dans la liste des process
	 */
	if (data->args->verbosity & V_OPERATIONS)
		ft_printf("P   %2i | forked\n", process->champion_id);
	increment_pc(data, process, offset);

}
