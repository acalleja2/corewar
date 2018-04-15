#include "corewar.h"

int			ncurses_main_loop(WINDOW *map, t_data *data)
{
	int		ch;

	if (data->args->ncurses == -1 || !map)
		return (-1);
	print_map(map, HEIGHT, WIDTH, data);
	ch = wgetch(map);
	if (ch == 'q')
		return (0);
	wrefresh_sleep(map, 1);
	return (1);
}

/*
** Detruit la fenetre d'affiche du corewar et la fenetre d'affichage  principale
**
*/
void		end_ncurses(WINDOW *map)
{
	if (map)
		return ;
	refresh_sleep(1);
	destroy_win(map);
	endwin();
}

/*
** Creer la fenetre principale, la fenetre d'affichage du corewar, affiche
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
	getmaxyx(stdscr, cols, rows);
	print_usage(rows, cols);
	refresh_sleep(1);
	map = create_newwin(HEIGHT + 2, WIDTH + 2, STARTX, STARTY); 
	nodelay(map, TRUE);
	return (map);
}
