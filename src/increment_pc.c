#include "corewar.h"

void		increment_pc(t_data *data, t_proc *process, int offset)
{
	int		pos;
	int		i;
	char	buf[80];

	pos = 0;
	if (data->args->verbosity & V_PC)
	{
		pos += ft_sprintf(buf + pos, "ADV %i (%#.4x -> %#.4x) ",
				offset,
				process->starting_pos + process->pc,
				process->starting_pos + process->pc + offset);
		i = 0;
		while (i < offset)
		{
			pos += ft_sprintf(buf + pos, "%.2x ", mem_get_byte(data, process,
						i));
			i += 1;
		}
		buf[pos] = '\n';
		write(1, buf, pos + 1);
	}
	process->pc += offset;
}
