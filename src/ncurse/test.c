#include <ncurses.h>

int		main(void)
{
	initscr();	/* start curses mode */
	printw("nwfnqweflnqwlkefnqwef\n");
	refresh(); /*print on screen */
	getch(); /* get user input */
	endwin();
	return (0);
}
