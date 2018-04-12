#include "corewar.h"

/*
** Si arg est -b, deux possibilites. Soit on a pas de parametres, et donc b = 0
** soit le parametre -stealth complete b, et b = 1
** Sinon on fait rien, et on reprends le parsing
*/
void		ft_b(int argc, char *argv[], int *i, t_args *args)
{
	if (args->dump != -1 || args->cycles != -1 || args->verbosity != -1 ||
			args->ncurses != -1)
		ft_error_parse();
	if (args->binary_output != -1)
		ft_error_parse();
	if (*i + 1 < argc && !ft_strcmp(argv[*i + 1], "--stealth"))
	{
		args->binary_output = 1;
		*i += 2;
	}
	else
	{
		*i += 1;
		args->binary_output = 0;
	}
}
