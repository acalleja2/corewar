#include <ncurses.h>
#include <unistd.h>
#include "../corewar.h"

#define HEIGHT 	64
#define WIDTH 192
#define STARTX 10 
#define STARTY 10 

WINDOW		*create_newwin(int height, int width, int starty, int startx)
{
	WINDOW	*local_win;
	local_win = newwin(height, width, starty, startx);
	box(local_win, '|', '-');
	wmove(local_win, 1, 1);
	wrefresh(local_win);
	return (local_win);
}

void	clear_win(WINDOW *win, int height, int width)
{
	int		i;
	int		j;
	int		cp;

	j = 1;
	i = 1;
	cp = 0;
	while (j <= height)
	{
		while (i <= width)
		{
			mvwprintw(win, j, i, " ");
			i++;
			cp++;
		}
		i = 1;
		j++;
	}
	wrefresh(win);
}

void	destroy_win(WINDOW *local_win)
{
	int		rows;
	int		cols;

	getmaxyx(local_win, cols, rows);
	clear_win(local_win, cols - 2 , rows - 2);
	//wrefresh(local_win);
	mvwprintw(local_win, cols / 2, rows / 2, "BYE");
	wrefresh(local_win);
	sleep(1);
	wborder(local_win ,' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '); 
	clear_win(local_win, cols - 2 , rows - 2);
	wrefresh(local_win);
	sleep(1);
	delwin(local_win);
}

void	print_usage(int rows, int cols)
{
	mvprintw(0, rows / 2, "COREWAR NCURSE OUTPUT MODE\n");
	printw("q => quit");
	refresh();
}

void	print_map(WINDOW *win, int height, int width)
{
	int		i;
	int		j;
	int		cp;

	j = 1;
	i = 1;
	cp = 0;
	while (j <= height)
	{
		while (i <= width)
		{
			mvwprintw(win, j, i, "0");
			i++;
			cp++;
		}
		i = 1;
		j++;
	}
	wrefresh(win);
	//wprintw(win, "charaters printed: %d\n", cp);
}

int		main(void)
{
	int		ch;
	int		rows;
	int		cols;
	WINDOW	*map;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	getmaxyx(stdscr, cols, rows);
	print_usage(rows, cols);
	refresh();
	sleep(1);
	map = create_newwin(HEIGHT + 2, WIDTH + 2, STARTX, STARTY); 
	while (1)
	{
		print_map(map, HEIGHT, WIDTH);
		ch = wgetch(map);
		if (ch == 'q')
			break ;
		wrefresh(map);
	}
	sleep(1);
	destroy_win(map);
	endwin();
}
