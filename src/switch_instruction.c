#include "corewar.h"

void			switch_instruction(t_proc *process, unsigned char instruction, t_data *data)
{
	if (instruction >= 1 && instruction <= 16)
	{
		(*(g_tab[instruction]))(process, data);
	}
	else
	{
		process->pc += 1;
	}
}
