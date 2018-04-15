#include "corewar.h"

void			mem_setup_byte(t_mem *mem, unsigned char const byte, int const pos, int const id)
{
	mem->map[pos % MEM_SIZE] = byte;
	mem->owner[pos % MEM_SIZE] = id;
}

void			mem_set_byte(t_data *data, t_proc *process, int offset, unsigned char value)
{
	mem_setup_byte(data->mem,
			value,
			process->starting_pos + process->pc + offset,
			process->champion_id);
}

unsigned char	mem_get_byte(t_data *data, t_proc *process, int pos)
{
	return (data->mem->map[(process->starting_pos + process->pc + pos) % MEM_SIZE]);
}

void			print_mem(t_mem *mem)
{
	int			row;
	int			col;
	int			offset;
	char		buffer[MEM_SIZE * 4 + 100];

	row = 0;
	offset = 0;
	while (row * 64 < MEM_SIZE)
	{
		offset += ft_sprintf(buffer + offset, "%#.4x : ", row * 64);
		col = 0;
		while (col < 64 && row * 64 + col < MEM_SIZE)
		{
			offset += ft_sprintf(buffer + offset, "%.2x ", mem->map[row * 64 + col]);
			col += 1;
		}
		buffer[offset] = '\n';
		offset += 1;
		row += 1;
	}
	write(1, buffer, offset);
}

int				mem_get_int(t_data *data, t_proc *process, int offset)
{

	unsigned char	tmp[4];

	tmp[0] = mem_get_byte(data, process, offset + 3);
	tmp[1] = mem_get_byte(data, process, offset + 2);
	tmp[2] = mem_get_byte(data, process, offset + 1);
	tmp[3] = mem_get_byte(data, process, offset + 0);
	return (*(int*)tmp);
}

int				mem_get_short_int(t_data *data, t_proc *process, int offset)
{

	unsigned char	tmp[2];

	tmp[0] = mem_get_byte(data, process, offset + 1);
	tmp[1] = mem_get_byte(data, process, offset + 0);
	return ((int)(*(short int*)tmp));
}

void			mem_set_int(t_data *data, t_proc *process, int offset, int value)
{
	mem_set_byte(data, process, offset, (unsigned char)((value >> 24) & 0xff));
	mem_set_byte(data, process, offset + 1, (unsigned char)((value >> 16) & 0xff));
	mem_set_byte(data, process, offset + 2, (unsigned char)((value >> 8) & 0xff));
	mem_set_byte(data, process, offset + 3, (unsigned char)(value & 0xff));
}
