/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:01:13 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 14:01:13 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** La petite gestion d'erreur des familles
*/

int		error_reading(int readres, int expected, char *filename)
{
	if (readres < 0)
	{
		errorf("Could not read from file %s", filename);
		return (1);
	}
	if (readres != expected)
	{
		ft_printf("File %s is too short\n", filename);
		return (1);
	}
	return (0);
}

/*
** Ici on va juste check que le magic number est bon.
** On swap les chars pour se repasser en big-endian
*/

int		get_magic_number(int fd, t_champion *new, char *filename)
{
	char	buf[4];
	int		readres;

	readres = read(fd, buf, 4);
	if (error_reading(readres, 4, filename))
		return (1);
	swap_chars(buf, buf + 3);
	swap_chars(buf + 1, buf + 2);
	if (*(int*)buf != COREWAR_EXEC_MAGIC)
	{
		ft_printf("File %s has a bad magic number\n", filename);
		return (1);
	}
	return (0);
}

/*
** Ici on recupere le nom du programme
*/

int		get_program_name(int fd, t_champion *new, char *filename)
{
	char	buf[PROG_NAME_LENGTH + 1];
	int		readres;

	readres = read(fd, buf, PROG_NAME_LENGTH);
	if (error_reading(readres, PROG_NAME_LENGTH, filename))
		return (1);
	buf[readres + 1] = '\0';
	new->name = ft_strdup(buf);
	return (0);
}

int			no_null_byte(int fd, t_champion *new, char *filename)
{
	char	buf[4];
	int		readres;

	readres = read(fd, buf, 4);
	if (error_reading(readres, 4, filename))
		return (1);
	if (*(int*)buf)
	{
		ft_printf("File %s has no separating NULL byte\n", filename);
		return (1);
	}
	return (0);
}
