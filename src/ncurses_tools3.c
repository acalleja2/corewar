#include "corewar.h"

/*
**  Pareil que print_map, mais avec des couleurs.
*/

void		print_color_char(WINDOW *win, t_data *data, int row, int col)
{
	int		color_pair;

	if (data->colors)
	{
		if (!(color_pair = check_process_colors(win, data)))
			color_pair = find_colors(data,
					data->mem->owner[row * 64 + col]);
		wattron(win, COLOR_PAIR(color_pair));
		wprintw(win, "%.2x ", data->mem->map[row * 64 + col]);
		wattroff(win, COLOR_PAIR(color_pair));
	}
}

void	print_color_grid(WINDOW *win, t_data *data)
{
	int			row;
	int			col;
	int			offset;
	char		buffer[MEM_SIZE * 4 + 200];

	row = 0;
	offset = 0;
	while (row * 64 < MEM_SIZE)
	{
		col = 1;
		while (col < 64 && row * 64 + col < MEM_SIZE)
		{
			offset += ft_sprintf(buffer + offset, "%.2x ",
					data->mem->map[row * 64 + col]);
			print_color_char(win, data, row, col);
			col += 1;
		}
		wprintw(win, " |");
		if (row < 63)
			wprintw(win, "|  ");
		row += 1;
	}
}

void	print_map_colors(WINDOW *win, int height, int width, t_data *data)
{
	wprintw(win, " ");
	wprintw(win, " ");
	print_color_grid(win, data);
	wmove(win, 1, 1);
	wrefresh_sleep(win, 0);
}
