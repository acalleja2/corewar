/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_parameters2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:09:38 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 14:09:38 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			get_nth_register_value(t_proc *process, int n)
{
	if (n <= 0 || n > REG_NUMBER)
		return (0);
	return (process->registers[n]);
}

void		set_nth_register_value(t_proc *process, int n, int value)
{
	if (n <= 0 || n > REG_NUMBER)
		return ;
	process->registers[n] = value;
}
