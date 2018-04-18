#include "corewar.h"

void		ins_lld(t_proc *process, t_data *data)
{
	int				p1;
	int				p2;
	int				p3;
	int				offset;

	if (!process->instruction_started)
	{
		process->time_to_wait = 10 - 2;
		process->instruction_started = TRUE;
		return ;
	}
	process->instruction_started = FALSE;
	offset = get_ocp_3_direct_params(data, process, &p1, &p2, &p3);
	/* Ne pas faire ca, sinon on perd l'index. Je laisse le commentaire, sinon
	** je vais oublier et je vais la rechanger 12 fois avant de me dire que je
	**fais de la merde (lorenzo: "encore!"), et c'est pas cool du tout.
	**Maintenant je sais.
	**Ou en tous cas je pense savoir.
	**En vrai j'en sais rien, mais ca me parait pas trop debile.
	**if (is_second_param_register(data, process))
	**p2 = get_nth_register_value(process, p2);
	*/
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
