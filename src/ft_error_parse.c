#include "corewar.h"

void	more_printing(void)
{
	ft_printf("          - 1 : Show lives\n"
			"          - 2 : Show cycles\n"
			"          - 4 : Show operations (Params are NOT litteral ...)\n"
			"          - 8 : Show deaths\n"
			"         - 16 : Show PC movements (Except for jumps)\n"
			"#### NCURSES OUTPUT MODE #########################################"
			"##############\n"
			"    -n        : Ncurses output mode\n"
			"##################################################################"
			"##############\n"
			"####         MISC        #########################################"
			"##############\n"
			"    -t        : talkative mode\n"
			"    -r        : gay pride\n"
			);
}

void	ft_error_parse(void)
{
	ft_printf("Parse Error\nUsage: ./corewar [-d N -v N |"
			"-n | -n N Champion.cor]\n"
			"#### TEXT OUTPUT MODE ############################################"
			"##############\n"
			"    -d N      : Dumps memory after N cycles then exits\n"
			"    -v N      : Verbosity levels, can be added together to enable "
			"several\n"
			"          - 0 : Show only essentials\n");
	more_printing();
	exit(1);
}
