/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_parameters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 13:37:46 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/15 13:37:46 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			get_ocp_3_indirect_params(t_data *data, t_proc *process,
		int *p1, int *p2, ...)
{
	va_list	ap;
	int		*p3;
	int		offset;

	va_start(ap, p2);
	p3 = va_arg(ap, int*);
	va_end(ap);
	offset = 2;
	offset += ocp_get_param1_ind(data, process, offset, p1);
	offset += ocp_get_param2_ind(data, process, offset, p2);
	offset += ocp_get_param3_ind(data, process, offset, p3);
	return (offset);
}

int			get_ocp_3_direct_params(t_data *data, t_proc *process,
		int *p1, int *p2, ...)
{
	va_list	ap;
	int		*p3;
	int		offset;

	va_start(ap, p2);
	p3 = va_arg(ap, int*);
	va_end(ap);
	offset = 2;
	offset += ocp_get_param1(data, process, offset, p1);
	offset += ocp_get_param2(data, process, offset, p2);
	offset += ocp_get_param3(data, process, offset, p3);
	return (offset);
}

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
