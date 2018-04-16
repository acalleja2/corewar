#include "corewar.h"

void			print_winner(t_data *data, WINDOW *map)
{
	t_champion	*curr;
	char		winner_name[PROG_NAME_LENGTH + 1];
	int			winner_time;
	char		*speak;

	curr = data->champs;
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
	speak = str_join_n(3, "We have a winner, and his name is ", winner_name, "\n");
	if (data->args->ncurses != -1)
		ncurses_winner(speak, data, map);
	else
		write(1, speak, ft_strlen(speak));
	free(speak);
	if (data->args->talk)
	{
		speak = str_join_n(3, "echo \'We have a winner, and his name is",
				winner_name, "\' | espeak");
		system(speak); 
		free(speak);
		speak = NULL;
	}
}
