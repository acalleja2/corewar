#include "corewar.h"

void		ins_ldi(t_proc *process, t_data *data)
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
	set_nth_register_value(process, p3, p1 + p2);
	if (p1 + p2 == 0)
		process->carry = 1;
	if (data->args->verbosity & V_OPERATIONS)
		ft_printf("P   %2i | ldi %i + %i in %i\n", 
				process->champion_id, p1, p2, p1 + p2);
	increment_pc(data, process, offset);
}
