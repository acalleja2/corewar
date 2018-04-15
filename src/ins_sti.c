#include "corewar.h"

/*
** Store indirect
*/

void		ins_sti(t_proc *process, t_data *data)
{
	unsigned char	ocp;
	int				p1;
	int				p2;
	int				p3;
	int				p1b;
	int				p2b;
	int				p3b;
	int				p1c;
	int				p2c;
	int				p3c;
	int				offset;

	if (!process->instruction_started)
	{
		process->time_to_wait = 25 - 1;
		process->instruction_started = TRUE;
		return ;
	}
	process->instruction_started = FALSE;
	ocp = mem_get_byte(data, process, 1);
	offset = 2;
	offset += ocp_get_param1_ind(data, process, offset, &p1b);
	offset += ocp_get_param2_ind(data, process, offset, &p2b);
	offset += ocp_get_param3_ind(data, process, offset, &p3b);
	p1 = (int)mem_get_byte(data, process, 2);
	p2 = (int)mem_get_short_int(data, process, 3);
	p3 = (int)mem_get_short_int(data, process, 5);
	ft_printf("STI :\nocp = %x, p1 = %x, p2 = %x, p3 = %x\n",
			ocp, p1, p2, p3);
	ft_printf("STI :\nocp = %x, p1b = %x, p2b = %x, p3b = %x\n",
			ocp, p1b, p2b, p3b);
	process->pc += get_ocp_3_indirect_params(data, process, &p1c, &p2c, &p3c);
	ft_printf("STI :\nocp = %x, p1b = %x, p2b = %x, p3b = %x\n",
			ocp, p1c, p2c, p3c);
	mem_set_int(data, process, p2 + p3, process->registers[p1]);
	/* process->pc += 5; */
}
