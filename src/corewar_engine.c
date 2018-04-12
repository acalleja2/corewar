#include "corewar.h"

/*
** Fonction de test
*/
void	ft_print_list(t_proc *proc)
{
	while (proc->next != NULL)
	{
		ft_printf("%d\n", proc->process_nbr);
		proc = proc->next;
	}
}

/*
** Fonction de test
*/
void		ft_print_process(t_process *p)
{
	ft_printf("process_nbr: %d, fd: %d,filename %s\n", p->process_nbr, p->fd,
			p->filename);
}

/*
** Ici on va tenter de creer la liste avec tous les filenames qu'on nous a donnes
** On renvoie a la fin le nombre de process crees avec succes.
** On verifie s'ils foirent avec init_process()
** A la fin on renvoie count, le nombre de process crees avec succes.
*/
void	create_proc_list(t_args *args, t_proc **processes)
{
	int		i;
	int		count;
	t_proc	*new;

	i = 0;
	count = 0;
	while ((args->champions)[i] != NULL)
	{
		new = init_process(i, (args->champions)[i]);
		i += 1;
		if (new == NULL)
			continue ;
		proc_list_append(processes, processes, new);
	}
	return (count);
}


void	ft_corewar_engine(t_args *args)
{
	//unsigned char	memory[MEM_SIZE];
	int				counter;
	t_proc			*processes;

	create_proc_list(args, &processes);
	ft_print_list(processes);
	counter = CYCLE_TO_DIE + CYCLE_DELTA;
	while ((counter -= CYCLE_DELTA)) {
	}
	return ;
}
