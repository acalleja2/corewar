#include "corewar.h"

/*
** Prend un registre ou index en memoire et un registre. Stock la valeur du
** premier parametre dans le registre.
** Inverse de st.
*/
void		ins_ld(t_proc *process, t_data *data)
{
	int				p1;
	int				p2;
	int				p2_index;
	int				offset;

	if (!process->instruction_started)
	{
		process->time_to_wait = 5 - 2;
		process->instruction_started = TRUE;
		return ;
	}
	process->instruction_started = FALSE;
	offset = get_ocp_2_direct_params(data, process, &p1, &p2);
	if (is_second_param_register(data, process))
		p2 = get_nth_register_value(process, p2);
	set_nth_register_value(process, p2, p1);
	process->carry = !p1;
	if (data->args->verbosity & V_OPERATIONS)
		ft_printf("P   %2i | ld r%i %i\n"
				"       | -> store %i to %i\n",
				process->champion_id, p1, p2,
				 p1, p2);
	increment_pc(data, process, offset);
}
