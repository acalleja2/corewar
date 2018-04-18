#include "corewar.h"

/*
** Prends deux prametres en entree: un registre et un autre registre ou une
** position en memoire.
** Charge la valeur contenue dans le premier registre dans la position indiquee
** en second parametre.
** Inverse de ld
*/

void		ins_st(t_proc *process, t_data *data)
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
	p1 = get_nth_register_value(process, p1);
	if (is_second_param_register(data, process))
		set_nth_register_value(process, p2, get_nth_register_value(process,
					p1));
	else
		mem_set_int(data, process, p2, get_nth_register_value(process, p1));
	if (p1 == 0)
		process->carry = 1;
	if (data->args->verbosity & V_OPERATIONS)
		ft_printf("P   %2i | st r%i %i\n       | -> store %i to %i\n",
				process->champion_id, p1, p2,
				get_nth_register_value(process, p1), p2);
	increment_pc(data, process, offset);
}
