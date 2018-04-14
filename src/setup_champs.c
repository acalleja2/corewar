#include "corewar.h"

/*
** Ici on va tenter de creer la liste des champions avec tous les filenames
** qu'on nous a donnes on verifie s'ils foirent avec init_process()
** A la fin on renvoie count, le nombre de champions recuperes avec succes.
*/

int		create_champ_list(t_data *data)
{
	int			i;
	int			count;
	t_champion	*new;

	i = 0;
	count = 0;
	while (i < MAX_PLAYERS && (data->args->champions)[i] != NULL)
	{
		new = init_champion(count, (data->args->champions)[i]);
		i += 1;
		if (new == NULL)
			continue ;
		champ_list_append(data, new);
		data->args->champ_number += 1;
		count += 1;
	}
	return (count);
}

void	setup_champions(t_data *data)
{
	data->args->champ_number = 0;
	create_champ_list(data);
	return ;
}
