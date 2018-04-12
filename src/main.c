#include "corewar.h"

int		main(int argc, char *argv[])
{
	t_args	args;

	ft_init_t_args(&args);
	ft_parseargs(argc, argv, &args);
	//ft_corewar_engine(&args);
	return (0);
}
