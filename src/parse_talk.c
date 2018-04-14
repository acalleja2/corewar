#include "corewar.h"

/*
** Verifie aue l'optin -talk ne sit pas deja set. Si non, la set, si oui, error
*/
void		ft_t(char *argv[], int *i, t_args *args)
{
	if (args->talk == 0)
		args->talk = 1;
	else
		ft_error_parse();
	*i += 1;
}
