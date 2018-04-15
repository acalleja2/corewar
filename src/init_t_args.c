#include "corewar.h"

/*
** intialize les valeurs de args a des valeurs par defaut
*/
void	ft_init_t_args(t_args *args, t_mem *mem)
{
		args->dump = -1;
		args->cycles = -1;
		args->verbosity = 0;
		args->binary_output = -1;
		args->ncurses = -1;
		args->index = 0;
		args->process_curr = 0;
		args->talk = 0;
		args->champions = (char **)ealloc(sizeof(char *) * MAX_PLAYERS);
		ft_bzero(args->champions, sizeof(char *) * MAX_PLAYERS);
		args->process = (int *)ealloc(sizeof(int) * MAX_PLAYERS);
		ft_bzero(args->process, sizeof(int) * MAX_PLAYERS);
		ft_bzero(mem->map, MEM_SIZE);
		ft_memset(mem->owner, (char)-1, MEM_SIZE);
		mem->cycle = 0;
		mem->cycle_to_die = CYCLE_TO_DIE;
		mem->since_last_check = 0;
		mem->checks_since_last_decrement = 0;
}
