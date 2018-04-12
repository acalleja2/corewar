#include "corewar.h"

/*
** Si L'argument ne correspond a aucun flag, il s'agit d'un champion
** On lui attribue un process valide > process_max
*/
void		ft_parse_name(char *argv[], int *i, t_args *args)
{
	args->process[args->index] = args->process_max + 1;
	args->process_max += 1;
	printf("argv[%d]: %s\n", *i, argv[*i]);
	printf("\trgs->tindex: %d\n", args->index);
	args->champions[args->index] = ft_strdup(argv[*i]);
	printf("\tPK? args->tindex: %d\n", args->index);
	args->index += 1;
	printf("\trgs->tindex: %d\n", args->index);
	*i += 1;
}
