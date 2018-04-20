#include "corewar.h"

/*
** Store indirect
*/

void		ins_sti(t_proc *process, t_data *data)
{
	int				p1;
	int				p2;
	int				p3;
	int				offset;

	if (!process->instruction_started)
	{
		process->time_to_wait = 25 - 2;
		process->instruction_started = TRUE;
		return ;
	}
	process->instruction_started = FALSE;
	offset = get_ocp_3_indirect_params(data, process, &p1, &p2, &p3);
	mem_set_int(data, process, p2 + p3, get_nth_register_value(process, p1));
	if (data->args->verbosity & V_OPERATIONS)
		ft_printf("P   %2i | sti r%i %i %i\n"
				"       | -> store %i to %i + %i = %i\n",
				process->champion_id, p1, p2, p3,
				 get_nth_register_value(process, p1), p2, p3, p2 + p3);
	increment_pc(data, process, offset);
}
