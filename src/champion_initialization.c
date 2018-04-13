#include "corewar.h"

/*
** Pour l'instant on ouvre juste le fichier
** TODO recuperer le code
*/
int				get_champ_code(t_champion *new, char *filename)
{
	int			fd;
	int			error;

	error = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		errorf("Could not open file %s", filename);
		return (1);
	}
	if (get_magic_number(fd, new, filename)
			|| get_program_name(fd, new, filename)
			|| no_null_byte(fd, new, filename)
			|| get_byte_count(fd, new, filename)
			|| get_program_desc(fd, new, filename)
			|| no_null_byte(fd, new, filename))
		error = 1;
	if (close(fd) < 0)
		errorf("Could not close file %s", filename);
	return (error);
}

/*
** Initialise un process, essaye de recuperer son code puis
** initialise la structure.
** Si une erreur survient renvoie NULL.
*/
t_champion		*init_champion(int id, char *filename)
{
	t_champion		*new;

	new = ealloc(sizeof(t_champion));
	new->next = NULL;
	new->code = NULL;
	new->name = NULL;
	new->comment = NULL;
	new->filename = filename;
	if (get_champ_code(new, filename))
		return (freen(4, new, new->code, new->name, new->comment));
	new->id = id;
	ft_printf("succesfully created champion %s\n", filename);
	return (new);
}
