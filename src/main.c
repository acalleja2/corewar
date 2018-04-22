#include "corewar.h"

void			(*const g_tab[17])(t_proc *process, t_data *data) = {
	NULL,
	ins_live,
	ins_ld,
	ins_st,
	ins_add,
	ins_sub,
	ins_and,
	ins_or,
	ins_xor,
	ins_zjmp,
	ins_ldi,
	ins_sti,
	ins_fork,
	ins_lld,
	ins_lldi,
	ins_lfork,
	ins_aff};

static void			setup_data(t_mem *mem, t_args *args, t_data *data)
{
	data->mem = mem;
	data->args = args;
	data->procs = NULL;
	data->champs = NULL;
	data->colors = 0;
	data->speed = 1000;
	data->curr_cycle = 0;
	init_header(data);
}

static void			free_stuff(t_data *data)
{
	ft_free_t_args(data->args);
	free(data->mem->map);
	free(data->mem->owner);
}

static void	print_error_message(t_data *data)
{
	ft_printf("No valid champions found, aborting...\n");
	champ_list_free(&(data->champs));
}

int				main(int argc, char *argv[])
{
	t_args		args;
	t_mem		mem;
	t_data		data;

	ft_init_t_args(&args, &mem);
	ft_parseargs(argc, argv, &args);
	setup_data(&mem, &args, &data);
	setup_champions(&data);
	ft_print_champ_list(data.champs);
	if (args.champ_number == 0)
	{
		print_error_message(&data);
		return (1);
	}
	load_champs_and_setup_processes(&data);
	vm_loop(&data);
	proc_list_free(data.procs);
	ft_free_header(&data);
	champ_list_free(&(data.champs));
	free_stuff(&data);
	return (0);
}
