#include <ncurses.h>
#include <unistd.h>

void		print_stuff(void)
{
	int		i = 0;
	int		row;
	int		col;

	getmaxyx(stdscr, row, col);
	while (i < 127)
	{
		move(row/2, col/2);
		addch(i);
		refresh();
		sleep(2);
		i++;
	}
}

int			main(void)
{
	int		ch;
	int		row;
	int		col;

	initscr(); /* create a window called stdscr */
	raw(); /* Line buffering disabled, we don't have to press enter after input */
	keypad(stdscr, TRUE); /* We can use F1, etc... */
	getmaxyx(stdscr, row, col);
	printw("rows: %d, cols: %d\n", row, col);
	refresh();
	while (1)
	{
		printw("test:");
		ch = getch();
		if (ch == 'q')
		{
			print_stuff();
			break ;
		}
		printw("=> %c\n", ch);
		refresh();
	}
	endwin();
}
