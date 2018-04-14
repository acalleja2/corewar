#include "corewar.h"

/*
** Ajoute un process a la fin de la liste (ouais c'est obvious)
*/

void			champ_list_append(t_champion **list, t_champion *new)
{
	t_champion	*current;

	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	current = *list;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

void	ft_print_champ_list(t_champion *champ)
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

void			champ_list_free(t_champion **list)
{
	t_champion	*current;
	t_champion	*tmp;

	if (*list == NULL)
		return ;
	current = *list;
	while (current != NULL)
	{
		tmp = current->next;
		freen(4, current, current->code, current->name, current->comment);
		current = tmp;
	}
}

int				champ_list_len(t_champion **list)
{
	int			len;
	t_champion	*current;

	len = 0;
	current = *list;
	while (current != NULL)
	{
		len += 1;
		current = current->next;
	}
	return (len);
}

t_champion		*get_champion_by_id(t_champion *champs, int id)
{
	t_champion	*current;

	current = champs;
	while (current != NULL)
	{
		if (current->id == id)
			return (current);
		current = current->next;
	}
	return (NULL);
}
