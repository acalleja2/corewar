#include "corewar.h"

/*
** TODO FIX TOUT CE BORDEL
*/

void		ins_sti(t_proc *process, t_data *data)
{
	unsigned char	ocd;
	int				p1;
	int				p2;
	int				p3;
	int				offset;

	if (!process->instruction_started)
	{
		process->time_to_wait = 25 - 1;
		process->instruction_started = TRUE;
		return ;
	}
	process->instruction_started = FALSE;
	ocd = mem_get_byte(data, process, 1);
	offset = 2;
	p1 = (int)mem_get_byte(data, process, 2);
	p2 = (int)mem_get_short_int(data, process, 3);
	p3 = (int)mem_get_short_int(data, process, 5);
	ft_printf("STI :\nocd = %x, p1 = %x, p2 = %x, p3 = %x\n",
			ocd, p1, p2, p3);
	mem_set_int(data, process, p2 + p3, p1);
	process->pc += 5;
}
