#include <ncurses.h>
#include <unistd.h>
#include "../corewar.h"

#define HEIGHT 	64
#define WIDTH 192
#define STARTX 10 
#define STARTY 10 

typedef struct	s_win
{
	int			startx;
	int			starty;
	int			height;
	int			width;
}				t_win;

/*
void		ft_init_win(WINDOW *win, int *values)
{
	win->startx = values[0];
	win->starty = values[1];
	win->height = values[2];
	win->width = values[3];
}
*/

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
	int		cycles;

	cycles = 0;
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	getmaxyx(stdscr, cols, rows);
	print_usage(rows, cols);
	refresh();
	sleep(1);
	map = create_newwin(HEIGHT + 2, WIDTH + 2, STARTX, STARTY); 
	nodelay(map, TRUE);
	while (1)
	{
		//printw("cycles: %d\n", cycles++);
		print_map(map, HEIGHT, WIDTH);
		ch = wgetch(map);
		if (ch == 'q')
			break ;
		wrefresh(map);
		refresh();
	}
	sleep(1);
	destroy_win(map);
	endwin();
}
