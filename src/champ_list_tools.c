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
