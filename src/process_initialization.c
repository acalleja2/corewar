/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_initialization.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:43:10 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/12 14:43:10 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Pour l'instant on ouvre juste le fichier
** TODO recuperer le code
*/
int				get_process_code(t_proc *new, char *filename)
{
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		errorf("Could not open file %s", filename);
		return (1);
	}
	// ici on charge le programme en memoire
	if (close(fd) < 0)
		errorf("Could not close file %s", filename);
	return (0);
}

/*
** Initialise un process, essaye de recuperer son code puis initialise la structure.
** Si une erreur survient renvoie NULL.
*/

t_proc			*init_process(int i, char *filename)
{
	t_proc		*new;

	new = ealloc(sizeof(t_proc));
	if (!get_process_code(new, filename))
		return (freen(1, new));
	new->process_nbr = i;
	new->pc = 0;
	new->carry = 0;
	new->alive = 0;
	return (new);
}
