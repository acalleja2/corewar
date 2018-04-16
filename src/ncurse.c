#include "corewar.h"

int			ncurses_main_loop(WINDOW *map, t_data *data)
{
	int		ch;

	if (data->args->ncurses == -1 || !map)
		return (-1);
	if (data->colors)
		print_map_colors(map, HEIGHT, WIDTH, data);
	else
		print_map(map, HEIGHT, WIDTH, data);
	ch = wgetch(map);
	if (ch == 'q')
		return (0);
	//wrefresh_sleep(map, 1);
	return (1);
}

/*
** Detruit la fenetre d'affiche du corewar et la fenetre d'affichage  principale
**
*/
void		end_ncurses(WINDOW *map)
{
	if (!map)
		return ;
	destroy_win(map);
	endwin();
}

/*
** Si le terminal supporte les couleurs, attribue une couleur par joueur.
** Si plus de 6 joueurs, pas de couleurs(8 couleurs en tout, moins blanc et
** et noir).
*/
int		init_colors(t_data *data)
{
	int			colors[] = {COLOR_BLACK, COLOR_RED, COLOR_GREEN, COLOR_YELLOW, 
			COLOR_BLUE, COLOR_MAGENTA, COLOR_CYAN, COLOR_WHITE};
	t_champion	*curr;
	int			i;
	int			j;
	int			color_pair;

	i = 0;
	j = i + 1;
	color_pair = 1;
	curr = data->champs;
	if (!has_colors() || data->args->champ_number > 56)
		return(0);
	start_color();
	while (curr && i < 8)
	{
		init_pair(color_pair, colors[i], colors[j]);
		curr->color_pair = color_pair;
		/*
		printw("curr->color_pair: %d, front: %d, bask: %d\t", color_pair, colors[i],
				colors[j]);
		refresh();
		*/
		if (j + 1 > 8)
		{
			j = 0;
			i++;
		}
		else if (j + 1 == i)
			j += 2;
		else
			j++;
		color_pair += 1;
		curr = curr->next;
	}
	data->colors = 1;
	return (1);
}


/*
void		init_champ_colors(t_data *data)
{
}
*/

/*
** Creer la fenetre principale et la fenetre d'affichage du corewar, affiche
** l'usage, empeche l'echo des touches, et rend l'entree utilisateur non
** bloquante.
*/
WINDOW		*init_ncurse(t_data *data)
{
	int		rows;
	int		cols;
	WINDOW	*map;

	if (data->args->ncurses == -1)
		return (NULL);
	init_main_window();
	/*
	if (init_colors(data));
		init_champ_colors(data);
		*/
	init_colors(data);
	getmaxyx(stdscr, cols, rows);
	print_usage(rows, cols);
	refresh_sleep(1);
	map = create_newwin(HEIGHT + 2, WIDTH + 2, STARTX, STARTY); 
	nodelay(map, TRUE);
	return (map);
}
