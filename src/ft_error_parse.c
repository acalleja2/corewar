#include "corewar.h"

void	ft_error_parse()
{
	ft_printf("Parse Error\nUsage: ./corewar [d- N -s N -v N | -b --stealth | "
			"-n --stealth | -n N Champion.cor]\n"
			"#### TEXT OUTPUT MODE ############################################"
			"##############\n"
			"    -d N      : Dumps memory after N cycles then exits\n"
			"    -s N      : Runs N cycles, dumps memory, pauses, then repeats\n"
			"    -v N      : Verbosity levels, can be added together to enable "
			"several\n"
			"            - 0 : Show only essentials\n"
			"            - 1 : Show lives\n"
			"            - 2 : Show cycles\n"
			"            - 4 : Show operations (Params are NOT litteral ...)\n"
			"            - 8 : Show deaths\n"
			"            - 16 : Show PC movements (Except for jumps)\n"
			"#### BINARY OUTPUT MODE ##########################################"
			"##############\n"
			"    -b        : Binary output mode for corewar"
			"    --stealth : Hides the real contents of the memory\n"
			"#### NCURSES OUTPUT MODE #########################################"
			"##############\n"
			"    -n        : Ncurses output mode"
			"    --stealth : Hides the real contents of the memory\n"
			"##################################################################"
			"##############\n"
			);
	exit(1);
}
