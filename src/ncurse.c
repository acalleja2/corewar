#include "corewar.h"

void			print_control_pannel_header(void)
{
	mvprintw(STARTY, WIDTH + STARTX + 20, "PROCESS NAME");
	mvprintw(STARTY, WIDTH + STARTX + 60, "ID");
	mvprintw(STARTY, WIDTH + STARTX + 70, "SIZE(bytes)");
	mvprintw(STARTY, WIDTH + STARTX + 90, "LAST_SEEN_ALIVE");
	mvprintw(STARTY, WIDTH + STARTX + 110, "PROCESSES");
}

void			print_control_pannel_misc(t_data *data, int i)
{
	mvprintw(STARTY + 10 + i, WIDTH + STARTX + 20, " CYCLES TO DIE\t\t%d",
			CYCLE_TO_DIE);
	mvprintw(STARTY + 11 + i, WIDTH + STARTX + 20, " CYCLES DELTA\t\t%d",
			CYCLE_DELTA);
	mvprintw(STARTY + 13 + i, WIDTH + STARTX + 20, " CYCLES LEFT\t\t%d",
			data->mem->cycle_to_die);
	mvprintw(STARTY + 14 + i, WIDTH + STARTX + 20, " SINCE LAST CHECK\t\t%d",
			data->mem->since_last_check);
}

void			print_control_panel_processes(t_champion *curr, int i,
				char *name)
{
	mvprintw(STARTY + 2 + i, WIDTH + STARTX + 20, name);
	mvprintw(STARTY + 2 + i, WIDTH + STARTX + 60, "%d", curr->id);
	mvprintw(STARTY + 2 + i, WIDTH + STARTX + 70, "%d", curr->bytes);
	mvprintw(STARTY + 2 + i, WIDTH + STARTX + 90, "%d",
			curr->last_seen_alive);
	mvprintw(STARTY + 2 + i, WIDTH + STARTX + 110, "%d", curr->nbr_process);
}

void			print_control_pannel(t_data *data)
{
	t_champion	*curr;
	int			cols;
	int			rows;
	int			i;
	char		name[31];

	i = 0;
	count_process_by_champion(data);
	getmaxyx(stdscr, cols, rows);
	print_control_pannel_header();
	curr = data->champs;
	while (curr)
	{
		ft_strncpy(name, curr->name, 30);
		name[30] = '\0';
		print_control_panel_processes(curr, i, name);
		curr = curr->next;
		i++;
	}
	print_control_pannel_misc(data, i);
	refresh();
	reinit_process_by_champion(data);
}

int				ncurses_main_loop(WINDOW *map, t_data *data)
{
	int			ch;

	usleep(30);
	if (data->args->ncurses == -1 || !map)
		return (-1);
	if (data->colors)
		print_map_colors(map, HEIGHT, WIDTH, data);
	else
		print_map(map, HEIGHT, WIDTH, data);
	print_control_pannel(data);
	ch = wgetch(map);
	if (ch == 'q')
		return (0);
	if (ch == ' ')
		ncurse_pause(map);
	return (1);
}
