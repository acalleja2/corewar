#include "corewar.h"

void	ft_free_t_args(t_args *args)
{
	int		i;

	i = 0;
	while (i < args->index)
	{
		free(args->champions[i]);
		args->champions[i] = NULL;
		i++;
	}
	free(args->champions);
	args->champions = NULL;
	free(args->process);
	args->process = NULL;
}
