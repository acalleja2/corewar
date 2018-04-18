#include "corewar.h"

void		ins_lfork(t_proc *process, t_data *data)
{
	int				p1;
	int				p2;
	int				p3;
	int				offset;
	t_proc			*new;

	if (!process->instruction_started)
	{
		process->time_to_wait = 800 - 2;
		process->instruction_started = TRUE;
		return ;
	}
	offset = get_ocp_3_indirect_params(data, process, &p1, &p2, &p3);
	new = (t_proc*)ealloc(sizeof(t_proc));
	proc_cpy(process, new);
	new->pc = process->pc + (p1 % IDX_MOD);
	if (data->args->verbosity & V_OPERATIONS)
		ft_printf("P   %2i | lforked\n", process->champion_id);
	increment_pc(data, process, offset);
}
