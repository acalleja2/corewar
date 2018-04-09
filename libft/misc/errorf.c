/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 17:08:01 by florenzo          #+#    #+#             */
/*   Updated: 2018/03/10 17:08:01 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche un message formate avec printf sur la sortie standard
** puis affiche errno.
** Exemple:
** errorf("Could not read from file %s", filename);
*/


int				errorf(char *format, ...)
{
	va_list		args;
	int			res;

	va_start(args, format);
	res = ft_vprintf(format, args);
	va_end(args);
	perror(" ");
	return (res);
}
