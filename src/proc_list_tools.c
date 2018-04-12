/*
** Ajoute un process a la fin de la liste (ouais c'est obvious)
*/
void			proc_list_append(t_proc **list, t_proc *new)
{
	t_proc		*current;

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
