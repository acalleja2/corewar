#include "corewar.h"

/*
** Si L'argument ne correspond a aucun flag, il s'agit d'un champion
** On lui attribue un process valide > process_curr
*/
void		ft_parse_name(char *argv[], int *i, t_args *args)
{
	while (!ft_valid_process(args->process_curr, args))
		args->process_curr += 1;
	args->process[args->index] = args->process_curr;
	args->process_curr += 1;
	args->champions[args->index] = ft_strdup(argv[*i]);
	args->index += 1;
	*i += 1;
}
