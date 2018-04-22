/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:01:14 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 15:44:26 by mschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (proc->pc + proc->starting_pos == -1)
			return (proc->proc_color);
		proc = proc->next;
	}
	return (0);
}

void			finish_initialization(int *colors, int i)
{
	while (i < 7)
	{
		init_pair(i, colors[i - 1], -1);
		i++;
	}
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
				init_proc_color(curr_proc, colors, i);
			curr_proc = curr_proc->next;
		}
		curr_champ = curr_champ->next;
		i++;
		curr_proc = data->procs;
	}
	finish_initialization(colors, i);
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
