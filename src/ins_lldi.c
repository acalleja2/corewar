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
	offset = get_ocp_3_direct_params(data, process, &p1, &p2, &p3);
	if (is_first_param_register(data, process))
		p1 = get_nth_register_value(process, p1);
	set_nth_register_value(process, p2, p1);
	if (p1 == 0)
		process->carry = 1;
	if (data->args->verbosity & V_OPERATIONS)
		ft_printf("P   %2i | lld r%i %i\n"
				"       | -> store %i to %i\n",
				process->champion_id, p1, p2,
				 get_nth_register_value(process, p1), p2);
	increment_pc(data, process, offset);
}
