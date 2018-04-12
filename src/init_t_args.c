#include "corewar.h"

/*
** intialize les valeurs de args a des valeurs par defaut
*/
void	ft_init_t_args(t_args *args)
{
		args->dump = -1;
		args->cycles = -1;
		args->verbosity = -1;
		args->binary_output = -1;
		args->ncurses = -1;
		args->index = 0;
		args->process_curr = 0;
		args->champions = (char **)ealloc(sizeof(char *) * MAX_PLAYERS);
		ft_bzero(args->champions, sizeof(char *) * MAX_PLAYERS);
		args->process = (int *)ealloc(sizeof(int) * MAX_PLAYERS);
		ft_bzero(args->process, sizeof(int) * MAX_PLAYERS);
}
