/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_talk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:59:07 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 15:42:36 by mschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Verifie aue l'optin -talk ne sit pas deja set. Si non, la set, si oui, error
*/

void		ft_t(int *i, t_args *args)
{
	if (args->talk == 0)
		args->talk = 1;
	else
		ft_error_parse();
	*i += 1;
}
