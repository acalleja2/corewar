#include "corewar.h"

int		main(int argc, char *argv[])
{
	t_args		args;
	t_champion	*champs;
	t_mem		mem;

	ft_init_t_args(&args, &mem);
	ft_parseargs(argc, argv, &args);
	setup_champions(&args, &champs);
	ft_free_t_args(&args);
	ft_print_champ_list(champs);
	if (args.champ_number == 0)
	{
		ft_printf("No valid champions found, aborting...\n");
		return (1);
	}
	load_champs_and_setup_processes(&args, &champs, &mem);
	print_proc_list(&mem);
	print_mem(&mem);
	/* vm_loop(&mem, &champs); */
	proc_list_free(&mem);
	champ_list_free(&champs);
	return (0);
}
