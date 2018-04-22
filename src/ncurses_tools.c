/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:53:10 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 15:38:57 by mschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Creer une nouvelle fenetre de taille height, de largeur width, et
** l'affiche aux coordonnees (starty, startx)
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

/*
**  Supprime tout le contenu d'une fenetre et le remplace par des espaces
**  Conserve la bordure de la fenetre
*/

void		clear_win(WINDOW *win, int height, int width)
{
	int		i;
	int		j;

	j = 1;
	i = 1;
	while (j <= height)
	{
		while (i <= width)
		{
			mvwprintw(win, j, i, " ");
			i++;
		}
		i = 1;
		j++;
	}
	wmove(win, 1, 1);
	wrefresh(win);
}

/*
**  Supprime tout le contenu d'une fenetre, ses bordure, et affiche un message
**  avant de quitter.
*/

void		destroy_win(WINDOW *local_win)
{
	int		rows;
	int		cols;

	getmaxyx(local_win, cols, rows);
	clear_win(local_win, cols - 2, rows - 2);
	mvwprintw(local_win, cols / 2, rows / 2, "BYE");
	wrefresh(local_win);
	sleep(1);
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	clear_win(local_win, cols - 2, rows - 2);
	wrefresh(local_win);
	delwin(local_win);
}

void		add_chars(int nbr, int *offset, char *buffer, ...)
{
	va_list	ap;
	int		i;
	char	c;

	i = 0;
	va_start(ap, buffer);
	while (i < nbr)
	{
		c = (char)va_arg(ap, int);
		buffer[(*offset)++] = c;
	}
	va_end(ap);
}

/*
**  Affiche le contenu de t_mem dans la fenetre reservee a corewar.
** On stocke tout dans un buffer, puis on fait un gros wprintw (print on a
** window), et on refresh la fenetre de la map.
*/

void		print_map(WINDOW *win, t_data *data)
{
	int		row;
	int		col;
	int		offset;
	char	buffer[MEM_SIZE * 4 + 200];

	row = 0;
	offset = 0;
	add_chars(2, &offset, buffer, ' ', ' ');
	while (row * 64 < MEM_SIZE)
	{
		col = 1;
		while (col < 64 && row * 64 + col < MEM_SIZE)
		{
			offset += ft_sprintf(buffer + offset, "%.2x ",
					data->mem->map[row * 64 + col]);
			col += 1;
		}
		add_chars(2, &offset, buffer, ' ', '|');
		if (row < 63)
			add_chars(3, &offset, buffer, '|', ' ', ' ');
		row += 1;
	}
	buffer[offset++] = '\0';
	wprintw(win, buffer);
	wrefresh_sleep(win, 0);
}
