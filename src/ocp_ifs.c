/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp_ifs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:57:38 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 13:57:38 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			is_first_param_register(t_data *data, t_proc *process)
{
	int		ocp;

	ocp = mem_get_byte(data, process, 1);
	return (((ocp >> 6) & 1) && !((ocp >> 6) & 2));
}

int			is_second_param_register(t_data *data, t_proc *process)
{
	int		ocp;

	ocp = mem_get_byte(data, process, 1);
	return (((ocp >> 4) & 1) && !((ocp >> 4) & 2));
}

int			is_third_param_register(t_data *data, t_proc *process)
{
	int		ocp;

	ocp = mem_get_byte(data, process, 1);
	return (((ocp >> 2) & 1) && !((ocp >> 2) & 2));
}
