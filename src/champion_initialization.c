#include "corewar.h"
/*
** Pour l'instant on ouvre juste le fichier
** TODO recuperer le code
*/
int				get_champ_code(t_champion *new, char *filename)
{
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		errorf("Could not open file %s", filename);
		return (1);
	}
	// ici on charge le programme en memoire
	if (close(fd) < 0)
		errorf("Could not close file %s", filename);
	return (0);
}

/*
** Initialise un process, essaye de recuperer son code puis initialise la structure.
** Si une erreur survient renvoie NULL.
*/
t_champion		*init_champion(int id, char *filename)
{
	t_champion		*new;

	new = ealloc(sizeof(t_champion));
	if (get_champ_code(new, filename))
		return (freen(1, new));
	new->id = id;
	new->next = NULL;
	new->filename = filename;
	ft_printf("succesfully created champion %s\n", filename);
	return (new);
}
