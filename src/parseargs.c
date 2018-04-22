/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:55:17 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 13:55:17 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Verifie si le numero de process est valide. Si pas valide, lui attribue
*/

int			ft_valid_process(int candidate, t_args *args)
{
	int		i;

	i = 0;
	while (i < args->index)
	{
		if (args->process[i] == candidate)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void		chec_args(int argc)
{
	if (argc < 2)
		ft_error_parse();
}

/*
** Recupere les arguments et les place dans t_args
** A chaque tour de boucle, verifie si arg est valide ou pas.
** Si l'arg est valide, le place dans la strucut t_arg.
** Si l'argument ne correspond a aucun argument valide, affiche l'usage et exit
** On peut prendre les arguments dans n'import quel ordre tant aue le format
** est valide.
*/

void		ft_parseargs(int argc, char *argv[], t_args *args)
{
	int		i;

	i = 1;
	check_args(argc);
	while (i < argc)
	{
		if (!strcmp(argv[i], "-d"))
			ft_d(argc, argv, &i, args);
		else if (!ft_strcmp(argv[i], "-s"))
			ft_s(argc, argv, &i, args);
		else if (!ft_strcmp(argv[i], "-v"))
			ft_v(argc, argv, &i, args);
		else if (!ft_strcmp(argv[i], "-b"))
			ft_b(argc, argv, &i, args);
		else if (!ft_strcmp(argv[i], "-n"))
			ft_n(argc, argv, &i, args);
		else if (!ft_strcmp(argv[i], "-t"))
			ft_t(argv, &i, args);
		else if (!ft_strcmp(argv[i], "-r"))
			ft_rainbow(argv, &i, args);
		else if (args->index < MAX_PLAYERS)
			ft_parse_name(argv, &i, args);
		else
			ft_error_parse();
	}
}
