#include "corewar.h"

/*
** Pas le droit au switch case donc on passe par un tableau de pointeurs sur
** fonction.
** On commence par verifier qu'il s'agit d'un opcode valide. Si ce n'est pas le
** cas on se contente de faire avancer de un le process.
** Si c'est valide on execute l'instruction.
*/

void			switch_instruction(t_proc *process, unsigned char instruction,
		t_data *data)
{
	if (instruction >= 1 && instruction <= 16)
	{
		ft_printf("le process %i execute l'instruction %i\n", process->debug, instruction);
		(*(g_tab[instruction]))(process, data);
	}
	else
	{
		process->pc += 1;
	}
}
