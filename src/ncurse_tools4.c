#include "corewar.h"

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
	init_colors(data);
	getmaxyx(stdscr, cols, rows);
	print_usage(rows, cols);
	refresh_sleep(1);
	map = create_newwin(HEIGHT + 2, WIDTH + 2, STARTX, STARTY);
	nodelay(map, TRUE);
	//data->header->header = generate_header();
	return (map);
}

/*
** Detruit la fenetre d'affiche du corewar et la fenetre d'affichage  principale
*/

void		end_ncurses(WINDOW *map)
{
	if (!map)
		return ;
	destroy_win(map);
	endwin();
}

void		count_process_by_champion(t_data *data)
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

void		reinit_process_by_champion(t_data *data)
{
	t_champion	*champ;

	champ = data->champs;
	while (champ)
	{
		champ->nbr_process = 0;
		champ = champ->next;
	}
}

void		ncurse_pause(WINDOW *map, int *keep_going)
{
	int		ch;
	int		cols;
	int		rows;

	getmaxyx(stdscr, cols, rows);
	nodelay(map, FALSE);
	mvprintw(0, rows / 2, "COREWAR NCURSE OUTPUT MODE: PAUSE\n");
	refresh();
	ch = wgetch(map);
	while (ch != ' ')
	{
		if (ch == 'q')
		{
			end_ncurses(map);
			*keep_going = 0;
			break ;
		}
		ch = wgetch(map);
	}
	nodelay(map, TRUE);
	mvprintw(0, rows / 2, "COREWAR NCURSE OUTPUT MODE       \n");
	refresh();
}
