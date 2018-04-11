#include "corewar.h"

/*
** intialize les valeurs de args a des valeurs improbables
*/
void	ft_init_t_args(t_args *args)
{
		args->dump = -1;
		args->cycles = -1;
		args->verbosity = -1;
		args->binary_output = -1;
		args->ncurses = -1;
		args->process1 = -1;
		args->process2 = -1;
		args->champ1 = NULL;
		args->champ2 = NULL;
}
