#include "corewar.h"

void			process_exec(t_data *data, t_proc *process)
{
	unsigned char		instruction;

	if (process->time_to_wait > 0)
	{
		process->time_to_wait -= 1;
		return ;
	}
	instruction = mem_get_byte(data, process, 0);
	switch_instruction(process, instruction, data);
}

void			exec_cycle(t_data *data)
{
	t_proc		*current;

	current = data->procs;
	while (current != NULL)
	{
		process_exec(data, current);
		current = current->next;
	}
}

void			vm_loop(t_data *data)
{
	WINDOW		*map;

	map = init_ncurse(data);
	while (42)
	{
		if (data->args->ncurses != -1)
		{
			if (!ncurses_main_loop(map, data))
				break ;
		}
		else if (data->mem->cycle == data->args->dump)
		{
			print_mem(data->mem);
			return ;
		}
		exec_cycle(data);
		/*
		printw("JE C PA SE KE JE FE LOL\n");
		refresh();
		*/
		if (data->mem->since_last_check == data->mem->cycle_to_die)
			if (!mem_check_alive(data))
			{
				if (data->args->ncurses == -1)
					ft_printf("We got a winner after %i cycles :\n", 
							data->mem->cycle);
				print_winner(data, map);
				break ;
			}
		data->mem->cycle += 1;
		data->mem->since_last_check += 1;
	}
	end_ncurses(map);
}
