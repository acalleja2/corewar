#include "corewar.h"

void		ins_lldi(t_proc *process, t_data *data)
{
	int				p1;
	int				p2;
	int				p3;
	int				offset;

	if (!process->instruction_started)
	{
		process->time_to_wait = 5 - 2;
		process->instruction_started = TRUE;
		return ;
	}
	process->instruction_started = FALSE;
	offset = get_ocp_3_indirect_params(data, process, &p1, &p2, &p3);
	if (is_first_param_register(data, process))
		p1 = get_nth_register_value(process, p1);
	set_nth_register_value(process, p3, mem_get_byte(data, process, p1 + p2));
	process->carry = !mem_get_byte(data, process, p1 + p2);
	if (data->args->verbosity & V_OPERATIONS)
		ft_printf("P   %2i | lldi %i %i\n"
				"       | -> store %i to r%i\n",
				process->champion_id, p1, p2, p3,
				mem_get_byte(data, process, p1 + p2), p3);
	increment_pc(data, process, offset);
}
