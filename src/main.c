#include "corewar.h"

void			(*const g_tab[17])(t_mem *mem,
		t_proc *process,
		t_champion *champs,
		t_args *args) = {
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

int		main(int argc, char *argv[])
{
	t_args		args;
	t_champion	*champs;
	t_mem		mem;

	ft_init_t_args(&args, &mem);
	ft_parseargs(argc, argv, &args);
	setup_champions(&args, &champs);
	ft_print_champ_list(champs);
	mem.champs = champs;
	mem.args = &args;
	if (args.champ_number == 0)
	{
		ft_printf("No valid champions found, aborting...\n");
		return (1);
	}
	load_champs_and_setup_processes(&args, &champs, &mem);
	print_proc_list(&mem);
	print_mem(&mem);
	vm_loop(&mem, champs, &args);
	proc_list_free(&mem);
	champ_list_free(&champs);
	ft_free_t_args(&args);
	return (0);
}
