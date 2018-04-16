#include "corewar.h"

/*
**  Refresh la fenetre principale et sleep 'sleep_time'
*/
void	refresh_sleep(int sleep_time)
{
	refresh();
	if (sleep_time > 0)
		sleep(sleep_time);
}

/*
**  Refresh la fenetre en parametre et sleep 'sleep_time'
*/
void	wrefresh_sleep(WINDOW *win, int sleep_time)
{
	wrefresh(win);
	if (sleep_time > 0)
		sleep(sleep_time);
}

/*
**  Affiche l'usage.
*/
void	print_usage(int rows, int cols)
{
	mvprintw(0, rows / 2, "COREWAR NCURSE OUTPUT MODE\n");
	printw("q         quit\n");
	printw("espace    pause/continue");
	refresh();
}


/*
**  Set certaines fonctionnalites: permet l'usage des touches fonctions,
**  ne reaffiche pas les entrees utilisateurs, et creet la fenetre principale.
*/
void	init_main_window()
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
}

/*
**  Affiche le winner sur la fenetre de corewar (pas la principale)
*/
void	ncurses_winner(char	*speak, t_data *data, WINDOW *map)
{
	int		cols;
	int		rows;

	if (data->args->ncurses == -1 || !map)
		return ;
	getmaxyx(map, cols, rows);
	clear_win(map, cols - 2, rows - 2);
	mvwprintw(map, cols / 2, (rows / 2) - ft_strlen(speak) / 2, speak);
	wrefresh_sleep(map, 2);
	clear_win(map, cols - 2, rows - 2);
	wrefresh_sleep(map, 1);
}
