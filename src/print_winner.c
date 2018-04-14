#include "corewar.h"

void			ft_print_winner(t_champion *champ)
{
	t_champion	*curr;
	char		winner_name[100];
	int			winner_time;
	char		*speak;

	curr = champ;
	ft_bzero(winner_name, sizeof(char) * 100);
	ft_bzero(location, sizeof(char) * 100);
	while (curr != NULL)
	{
		if (curr->last_seen_alive > winner_time)
		{
			winner_time = curr->last_seen_alive;
			winner_name = ft_strcpy(winer_game, curr->name);
		}
		curr = curr->next;
	}
	speak = ft_strjoin("espeak the winner is ", winner_name);
	write(1, speak ft_strlen(speak));
	/*
	if (args->talk)
	{
		free(speak);
		speak = str_join_n(3, "echo \"The winner is ", winner_name, " | espeak");
		system(speak); 
		free(speak);
		speak = NULL;
	}
	*/
}
