#include "corewar.h"

void	init_proc_color(t_proc *curr_proc, int *colors, int i)
{
	curr_proc->proc_color = i + 6;
	init_pair(i + 6, colors[i], -1);
}

void	finish_header(char **header)
{
	header[5] = " > (_)  )  __: (  '\\_/ \\   ;|  |\\ \\  |  |'  \\   .---.|"
		"|/   \\|  |.'   _    ||  |\\ \\  |  | \0";
	header[6] = "(  .  .-'_/  )\\ `\\\"/  \\  ) / |  | \\ `'   / \\  `-'    /|"
		"' g  `  ||  _( )_  ||  | \\ `'   / \0";
	header[7] = " `-'`-'     /  '. \\_/``\\\".'  |  |  \\    /   \\       / |"
		"/\\    |\\ (_ o _) /|  |  \\    /  \0";
	header[8] = "   `._____.'     '-----'    ''-'   `'-'     `'-..-'  `---'   "
		"`---` '.(_,_).' ''-'   `'-'   \0";
	header[9] = "                                                            "
		"";
}
