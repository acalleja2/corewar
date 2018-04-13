#include "corewar.h"

/*
** Fonction de test
*/
void	ft_print_list(t_champion *champ)
{
	ft_printf("printing champ list :\n");
	if (champ == NULL)
	{
		ft_printf("No valid champions found :/\n");
		return ;
	}
	while (champ != NULL)
	{
		ft_printf("Champion %s from file %s has id %i and weights "
				"%i bytes\n" ITALIC "%s\n" CLEAR,
				champ->name, champ->filename, champ->id,
				champ->bytes, champ->comment);
		champ = champ->next;
	}
}

/*
** Fonction de test
*/
/* void	ft_print_process(t_proc *p)
{
	ft_printf("process_nbr: %d, fd: %d,filename %s\n", p->process_nbr, p->fd,
			p->filename);
} */

/*
** Ici on va tenter de creer la liste des champions avec tous les filenames 
** qu'on nous a donnes on verifie s'ils foirent avec init_process()
** A la fin on renvoie count, le nombre de champions recuperes avec succes.
*/
int		create_champ_list(t_args *args, t_champion **champs)
{
	int			i;
	int			count;
	t_champion	*new;

	i = 0;
	count = 0;
	while (i < MAX_PLAYERS && (args->champions)[i] != NULL)
	{
		new = init_champion(count, (args->champions)[i]);
		i += 1;
		if (new == NULL)
			continue ;
		champ_list_append(champs, new);
		count += 1;
	}
	return (count);
}


void	ft_corewar_engine(t_args *args)
{
	//unsigned char	memory[MEM_SIZE];
	int				counter;
	t_champion		*champs;

	champs = NULL;
	create_champ_list(args, &champs);
	ft_print_list(champs);
	counter = CYCLE_TO_DIE + CYCLE_DELTA;
	/* while ((counter -= CYCLE_DELTA)) { */
	/* } */
	return ;
}
