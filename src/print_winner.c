#include "corewar.h"

void			print_winner(t_champion *champ, t_args *args)
{
	t_champion	*curr;
	char		winner_name[PROG_NAME_LENGTH + 1];
	int			winner_time;
	char		*speak;

	curr = champ;
	ft_bzero(winner_name, sizeof(char) * (PROG_NAME_LENGTH + 1));
	winner_time = -1;
	while (curr != NULL)
	{
		if (curr->last_seen_alive > winner_time)
		{
			winner_time = curr->last_seen_alive;
			ft_strcpy(winner_name, curr->name);
		}
		curr = curr->next;
	}
	speak = str_join_n(3, "The winner is ", winner_name, "\n");
	write(1, speak, ft_strlen(speak));
	free(speak);
	if (args->talk)
	{
		speak = str_join_n(3, "echo \'The winner is ",
				winner_name, "\' | espeak");
		system(speak); 
		free(speak);
		speak = NULL;
	}
}
