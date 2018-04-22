/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse_tools5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:57:57 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 13:57:57 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		change_speed(WINDOW *map, t_data *data, int ch)
{
	if (ch == '-' && data->speed > 0)
		data->speed -= 500;
	else if (ch == '+')
		data->speed += 500;
}

char		**generate_header(void)
{
	char	**header;
	int		col;
	int		line;

	col = 0;
	line = 0;
	header = (char **)ealloc(sizeof(char *) * 10);
	header[0] = "    _______      ,-----.    .-------.        .-''-.  .--.    "
		".--.   ____    .-------.     \0";
	header[1] = "   /   __  \\   .'  .-,  '.  |  _ _   \\     .'_ _   ]\\ |  |_  "
	"|  | .'  __ `. |  _ _   \\    \0";
	header[2] = "  | ,_/  \\__) / ,-.|  \\ _ \\ | ( ' )  |    / ( ` )   '| _( )_ "
	"|  |/   '  \\  \\| ( ' )  |    \0";
	header[3] = ",-./  )      ;  \\  '_ /  | :|(_ o _) /   . (_ o _)  ||(_ o _)"
		"|  ||___|  /  ||(_ o _) /    \0";
	header[4] = "\\  '_ '`)    |  _`,/ \\ _/  || (_,_).' __ |  (_,_)___|| (_,_) "
		"\\ |  |   _.-`   || (_,_).' __  \0";
	header[5] = " > (_)  )  __: (  '\\_/ \\   ;|  |\\ \\  |  |'  \\   .---.|  |/   "
		"\\|  |.'   _    ||  |\\ \\  |  | \0";
	header[6] = "(  .  .-'_/  )\\ `\\\"/  \\  ) / |  | \\ `'   / \\  `-'    /|  ' "
		"g  `  ||  _( )_  ||  | \\ `'   / \0";
	header[7] = " `-'`-'     /  '. \\_/``\\\".'  |  |  \\    /   \\       / |    /"
		"\\    |\\ (_ o _) /|  |  \\    /  \0";
	header[8] = "   `._____.'     '-----'    ''-'   `'-'     `'-..-'  `---'   "
		"`---` '.(_,_).' ''-'   `'-'   \0";
	header[9] = "                                                            "
		"";
	return (header);
}

void		init_header(t_data *data)
{
	data->header = (t_header*)ealloc(sizeof(t_header));
	data->header->x = 93;
	data->header->y = 10;
	data->header->header = NULL;
	data->header->header = generate_header();
}

void			put_header(int x_top_left, int y_top_left, t_data *d)
{
	int			y;
	int			offset;
	char		**h;
	int			color;

	y = 0;
	offset = 0;
	color = 1;
	h = d->header->header;
	while (y < d->header->y)
	{
		if (color > 7)
			color = 1;
		if (d->colors)
			attron(COLOR_PAIR(color));
		mvprintw(x_top_left + offset, y_top_left, "%s\n", h[y]);
		if (d->colors)
			attroff(COLOR_PAIR(color));
		y++;
		offset++;
		color++;
	}
}

void			ft_free_header(t_data *data)
{
	int			i;
	t_header	*header;

	header = data->header;
	i = 0;
	while (i < header->y)
	{
		header->header[i] = NULL;
		i++;
	}
	free(header->header);
	header->header = NULL;
	free(data->header);
	data->header = NULL;
}
