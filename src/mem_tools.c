#include "corewar.h"

void			mem_set_byte(t_mem *mem, unsigned char const byte, int const pos, int const id)
{
	mem->map[pos % MEM_SIZE] = byte;
	mem->owner[pos % MEM_SIZE] = id;
}

unsigned char	mem_get_byte(t_mem *mem, t_proc *process, int pos)
{
	return (mem->map[(process->starting_pos + process->pc + pos) % MEM_SIZE]);
}

void			print_mem(t_mem *mem)
{
	int			row;
	int			col;

	row = 0;
	while (row * 64 < MEM_SIZE)
	{
		ft_printf("%#.4x : ", row * 64);
		col = 0;
		while (col < 64 && row * 64 + col < MEM_SIZE)
		{
			ft_printf("%.2x ", mem->map[row * 64 + col]);
			col += 1;
		}
		ft_printf("\n");
		row += 1;
	}
}
