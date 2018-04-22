/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:58:59 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 13:58:59 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** FONCTION DE TEST
*/

void	print_args(t_args *args)
{
	int		i;

	i = 0;
	ft_printf("print args\n");
	ft_printf("dump: %d\t", args->dump);
	ft_printf("cycles: %d\t", args->cycles);
	ft_printf("verbosity: %d\t", args->verbosity);
	ft_printf("binary_ouput: %d\t", args->binary_output);
	ft_printf("ncurses: %d\t", args->ncurses);
	ft_printf("args->index: %d\n", args->index);
	ft_printf("args->talk: %d\n", args->talk);
	while (i < args->index)
	{
		ft_printf("process: %d, champ: %s\n", args->process[i],
				args->champions[i]);
		i++;
	}
	ft_printf("end print args\n");
}
