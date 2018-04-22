/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:01:13 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 14:01:13 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_free_t_args(t_args *args)
{
	int		i;

	i = 0;
	while (i < args->index)
	{
		free(args->champions[i]);
		args->champions[i] = NULL;
		i++;
	}
	free(args->champions);
	args->champions = NULL;
	free(args->process);
	args->process = NULL;
}
