#include <ncurses.h>
#include <unistd.h>
#include "../corewar.h"

int		main(void)
{
	int		ch;
	int		rows;
	int		cols;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, cols, rows);
	printw("rows: %d, cols: %d\n", rows, cols);
	//mvprintw(rows / 2, cols / 2, "rergwergwergwe\n");
	mvprintw(cols /2, rows / 2, "rergwergwergwe\n");
	//mvprintw(100, 36, "rergwergwergwe\n");
	//printw("rrararasraerasraer\n");
	refresh();
	sleep(2);
	endwin();
	
	return (0);
}
