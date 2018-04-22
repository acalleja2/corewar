/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:01:16 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 14:01:16 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Gere l'option n s'il s'agit d'un name
*/

void		ft_n_name(char *argv[], int *i, t_args *args)
{
	if (ft_valid_process(ft_atoi(argv[*i + 1]), args))
		args->process[args->index] = ft_atoi(argv[*i + 1]);
	else
	{
		while (!ft_valid_process(args->process_curr, args))
			args->process_curr += 1;
		args->process[args->index] = args->process_curr;
		args->process_curr += 1;
	}
	args->champions[args->index] = ft_strdup(argv[*i + 2]);
	args->index += 1;
	*i += 3;
}

/*
** Gere l'option n s'il s'agit de ncurse
*/

void		ft_n_curse(int argc, char *argv[], int *i, t_args *args)
{
	if (args->dump != -1 || args->cycles != -1 || args->verbosity != 0 ||
			args->binary_output != -1)
		ft_error_parse();
	if (*i + 1 < argc && !ft_strcmp(argv[*i + 1], "--stealth"))
	{
		args->ncurses = 1;
		*i += 2;
	}
	else
	{
		*i += 1;
		args->ncurses = 0;
	}
}

/*
** Deux possibilites pour n. Soit n de format n || n --stealth => option ncurse
** soit n de format -n nbr name, auquel cas n est un champion avec nbr le
** numero de process.
*/

void		ft_n(int argc, char *argv[], int *i, t_args *args)
{
	if (*i + 2 < argc && ft_strisnumber(argv[*i + 1]) &&
			args->index < MAX_PLAYERS)
		ft_n_name(argv, i, args);
	else
		ft_n_curse(argc, argv, i, args);
}
