#include "corewar.h"

/*
** FONCTION DE TEST
*/
void	print_args(t_args *args)
{
	int		i;

	i = 0;
	printf("print args\n");
	printf("dump: %d\t", args->dump);
	printf("cycles: %d\t", args->cycles);
	printf("verbosity: %d\t", args->verbosity);
	printf("binary_ouput: %d\t", args->binary_output);
	printf("ncurses: %d\t", args->ncurses);
	printf("args->index: %d\n", args->index);
	printf("args->talk: %d\n", args->talk);
	while (i < args->index)
	{
		printf("process: %d, champ: %s\n", args->process[i], 
				args->champions[i]);
		i++;
	}
	printf("end print args\n");
}
