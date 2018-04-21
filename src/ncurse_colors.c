#include "corewar.h"

int				find_colors(t_data *data, int id)
{
	t_champion	*curr;

	curr = data->champs;
	while (curr != NULL)
	{
		if (curr->id == id)
			return (curr->color_pair);
		curr = curr->next;
	}
	return (0);
}

/*
** verifie si la position correpond a un process. Si oui, inverse les
** couleurs background foreground.
*/

int				check_process_colors(WINDOW *win, t_data *data)
{
	t_proc		*proc;
	int			x;
	int			y;

	proc = data->procs;
	getyx(win, y, x);
	while (proc)
	{
		if (proc->starting_pos == (y - 1) * 192 + x)
			return (proc->proc_color);
		proc = proc->next;
	}
	return (0);
}

void			champ_color_pair(int *colors, t_data *data)
{
	t_champion	*curr_champ;
	t_proc		*curr_proc;
	int			i;

	curr_champ = data->champs;
	curr_proc = data->procs;
	i = 1;
	while (curr_champ)
	{
		init_pair(i, colors[i - 1], -1);
		curr_champ->color_pair = i;
		while (curr_proc)
		{
			if (curr_proc->champion_id == curr_champ->id)
			{
				curr_proc->proc_color = i + 6;
				init_pair(i + 6, colors[i], -1);
			}
			curr_proc = curr_proc->next;
		}
		curr_champ = curr_champ->next;
		i++;
		curr_proc = data->procs;
	}
	while (i < 7)
	{
		init_pair(i, colors[i - 1], -1);
		i++;
	}
}

/*
** Si le terminal supporte les couleurs, attribue une couleur par joueur.
** Si plus de 6 joueurs, pas de couleurs(8 couleurs en tout, moins blanc et
** et noir).
*/

int				init_colors(t_data *data)
{
	int	colors[6];

	colors[0] = COLOR_RED;
	colors[1] = COLOR_GREEN;
	colors[2] = COLOR_YELLOW;
	colors[3] = COLOR_BLUE;
	colors[4] = COLOR_MAGENTA;
	colors[5] = COLOR_CYAN;
	if (!has_colors() || data->args->champ_number > 6)
		return (0);
	start_color();
	use_default_colors();
	champ_color_pair(colors, data);
	data->colors = 1;
	return (1);
}
