#include "corewar.h"

void		ncurse_pause(WINDOW *map)
{
	int			ch;
	int			cols;
	int			rows;

	getmaxyx(stdscr, cols, rows);
	nodelay(map, FALSE);
	mvprintw(0, rows / 2, "COREWAR NCURSE OUTPUT MODE: PAUSE\n");
	refresh();
	ch = wgetch(map);
	while (ch != ' ')
		ch = wgetch(map);
	nodelay(map, TRUE);
	mvprintw(0, rows / 2, "COREWAR NCURSE OUTPUT MODE       \n");
	refresh();
}

void	count_process_by_champion(t_data *data)
{
	t_proc		*proc;
	t_champion	*champ;

	champ = data->champs;
	while (champ)
	{
		proc = data->procs;
		while (proc)
		{
			if (proc->champion_id == champ->id)
				champ->nbr_process += 1;
			proc = proc->next;
		}
		champ = champ->next;
	}
}

void	reinit_process_by_champion(t_data *data)
{
	t_champion	*champ;

	champ = data->champs;
	while (champ)
	{
		champ->nbr_process = 0;
		champ = champ->next;
	}
}

void		print_control_pannel(t_data *data)
{
	t_champion	*curr;
	int		cols;
	int		rows;
	int		i;
	char	name[31];

	i = 0;

	count_process_by_champion(data);
	getmaxyx(stdscr, cols, rows);
	curr = data->champs;
	mvprintw(STARTY, WIDTH + STARTX + 20, "PROCESS NAME");
	mvprintw(STARTY, WIDTH + STARTX + 60, "ID");
	mvprintw(STARTY, WIDTH + STARTX + 70, "SIZE(bytes)");
	mvprintw(STARTY, WIDTH + STARTX + 90, "LAST_SEEN_ALIVE");
	mvprintw(STARTY, WIDTH + STARTX + 110, "PROCESSES");
	while (curr)
	{
		ft_strncpy(name, curr->name, 30);
		name[30] = '\0';
		mvprintw(STARTY + 2 + i, WIDTH + STARTX + 20, name);
		mvprintw(STARTY + 2 + i, WIDTH + STARTX + 60, "%d", curr->id);
		mvprintw(STARTY + 2 + i, WIDTH + STARTX + 70, "%d", curr->bytes);
		mvprintw(STARTY + 2 + i, WIDTH + STARTX + 90, "%d", curr->last_seen_alive);
		mvprintw(STARTY + 2 + i, WIDTH + STARTX + 110, "%d", curr->nbr_process);
		curr = curr->next;
		i++;
	}
	mvprintw(STARTY + 10 + i, WIDTH + STARTX + 20, " CYCLES TO DIE\t\t%d", CYCLE_TO_DIE);
	mvprintw(STARTY + 11 + i, WIDTH + STARTX + 20, " CYCLES DELTA\t\t%d", CYCLE_DELTA);
	mvprintw(STARTY + 13 + i, WIDTH + STARTX + 20, " CYCLES LEFT\t\t%d", 
			data->mem->cycle_to_die);
	mvprintw(STARTY + 14 + i, WIDTH + STARTX + 20, " SINCE LAST CHECK\t\t%d", 
			data->mem->since_last_check);
	refresh();
	reinit_process_by_champion(data);
}

int			ncurses_main_loop(WINDOW *map, t_data *data)
{
	int		ch;

	if (data->args->ncurses == -1 || !map)
		return (-1);
	if (data->colors)
		print_map_colors(map, HEIGHT, WIDTH, data);
	else
		print_map(map, HEIGHT, WIDTH, data);
	print_control_pannel(data);
	ch = wgetch(map);
	//if (ch == 'q' || data->mem->cycle_to_die <= 0) /* S'arrete jamais a cause ca ? */
	if (ch == 'q') /* S'arrete jamais a cause ca ? */
		return (0);
	if (ch == ' ')
		ncurse_pause(map);
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
/*
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
*/

int		init_colors(t_data *data)
{
	int	colors[] = {COLOR_RED, COLOR_GREEN, COLOR_YELLOW, 
			COLOR_BLUE, COLOR_MAGENTA, COLOR_CYAN};
	t_champion	*curr_champ;
	t_proc		*curr_proc;
	int			i;

	i = 1;
	curr_champ = data->champs;
	curr_proc = data->procs;
	if (!has_colors() || data->args->champ_number > 6)
		return(0);
	start_color();
	use_default_colors();
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
			curr_proc = curr_proc ->next;
		}
		curr_champ = curr_champ->next;
		i++;
		curr_proc = data->procs;
	}
	data->colors = 1;
	return (1);
}

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
