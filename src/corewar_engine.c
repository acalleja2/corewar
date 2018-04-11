#include "corewar.h"

/*
** Fonction de test
*/
void	ft_print_list(t_proc *proc)
{
	while (proc->next)
	{
		ft_printf("%d\n", proc->process->process_nbr);
		proc = proc->next;
	}
}

/*
** Fonction de test
*/
void		ft_print_process(t_process *p)
{
	ft_printf("process_nbr: %d, fd: %d,\n", p->process_nbr, p->fd);
}

/*
** Add a process to the list of processes to be executed each cycle
*/
void	ft_lstpush(t_proc *processes, t_process *elem)
{
	t_proc	*new;

	new = (t_proc*)ealloc(sizeof(t_proc));
	new->process = elem;
	new->next = NULL;
	while (processes->next)
		processes = processes->next;
	processes->next = new;
}

/*
** Initialize a process
** Gives it its process_nbr (id), open file in fd, and gives default values
** to pc and carry
*/
void	ft_init_process(int flag, t_args *args, t_process *process)
{
	char	*file;

	process->pc = 0;
	process->carry = 0;
	process->process_nbr = (flag == 1) ? args->process1 : args->process2;
	file = (flag == 1) ? args->champ1 : args->champ2;
	process->fd = open(file, O_RDONLY);
	if (process->fd == -1)
		ft_error_file((flag == 1) ? args->champ1 : args->champ2);
}

/*
** Create the first two processes and push them in the list of processes
*/
void	ft_create_first_processes(t_args *args, t_proc *processes)
{
	t_process	*process1;
	t_process	*process2;

	process1 = (t_process*)ealloc(sizeof(t_process));
	process2 = (t_process*)ealloc(sizeof(t_process));
	if (args->process1 == args->process2)
		args->process2 = args->process1 + 1;
	ft_init_process(1, args, process1);
	ft_init_process(2, args, process1);
	ft_print_process(process1);
	ft_print_process(process2);
	ft_lstpush(processes, process1);
	ft_lstpush(processes, process2);
}


void	ft_corewar_engine(t_args *args)
{
	//unsigned char	memory[MEM_SIZE];
	int				counter;
	t_proc			*processes;

	processes = (t_proc*)ealloc(sizeof(t_proc));
	processes->next = NULL;
	processes->process = NULL;
	ft_create_first_processes(args, processes);
	ft_print_list(processes);
	counter = CYCLE_TO_DIE + CYCLE_DELTA;
	while ((counter -= CYCLE_DELTA)) {
	}
	return ;
}
