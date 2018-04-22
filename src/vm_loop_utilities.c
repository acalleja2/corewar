#include "corewar.h"

void		print_cycle_start_vm_loop(t_data *data)
{
	if (data->args->verbosity & V_CYCLES)
		print_cycle_start(data);
}

void		print_cycle_end_vm_loop(t_data *data)
{
	if (data->args->verbosity & V_CYCLES)
		print_cycle_end(data);
}
