#include "corewar.h"

void			switch_instruction(t_mem *mem, t_proc *process,
		t_champion *champs, unsigned char instruction)
{
	if (instruction >= 1 && instruction <= 16)
	{
		(*(g_tab[instruction]))(mem, process, champs);
	}
	else
	{
		process->pc += 1;
	}
}
