#include "corewar.h"

int			is_first_param_register(t_data *data, t_proc *process)
{
	int		ocp;

	ocp = mem_get_byte(data, process, 1);
	return (((ocp >> 6) & 1) && !((ocp >> 6) & 2));
}

int			is_second_param_register(t_data *data, t_proc *process)
{
	int		ocp;

	ocp = mem_get_byte(data, process, 1);
	return (((ocp >> 4) & 1) && !((ocp >> 4) & 2));
}

int			is_third_param_register(t_data *data, t_proc *process)
{
	int		ocp;

	ocp = mem_get_byte(data, process, 1);
	return (((ocp >> 2) & 1) && !((ocp >> 2) & 2));
}
