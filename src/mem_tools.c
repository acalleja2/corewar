#include "corewar.h"

/*
** Fonction "legacy" d'avant la refactorisation, ne vous en servez pas.
** elle sert de wrapper pour mem_set_byte et lors du chargement des programmes
** en memoire.
*/

void			mem_setup_byte(t_mem *mem, unsigned char const byte,
		int const pos, int const id)
{
	ft_printf("La map existe toujours: %p\n", mem->map);
	mem->map[pos % MEM_SIZE] = byte;
	mem->owner[pos % MEM_SIZE] = id;
}

/*
** Cette fonction permet a un process de set un octet situe offset octets apres
** son emplacement logique.
** map->owner est mis a jour par la meme occasion afin d'avoir les bonnes
** couleurs.
*/

void			mem_set_byte(t_data *data, t_proc *process, int offset,
		unsigned char value)
{
	mem_setup_byte(data->mem,
			value,
			process->starting_pos + process->pc + offset,
			process->champion_id);
}

/*
** Renvoie la valeur de l'octet pos octets apres l'emplacement logique du
** process.
** J'appelle "emplacement logique" la position de depart du process + son pc.
** Comme il se peut que le PC soit tres eleve on n'oublie pas le petit modulo.
*/

unsigned char	mem_get_byte(t_data *data, t_proc *process, int pos)
{
	ft_printf("process : %p\n", process);
	ft_printf("process->starting_pos : %p\n", process->starting_pos);
	ft_printf("process->pc : %p\n", process->pc);
	ft_printf("pos : %p\n", pos);
	return (data->mem->map[(process->starting_pos + process->pc + pos)
			% MEM_SIZE]);
}

/*
** Dump la memoire comme au format de la VM.
** Pour optimiser on cree un buffer et on fait un seul write.
** Pour comprendre comment ca marche : man 3 printf (lol)
*/

void			print_mem(t_mem *mem)
{
	int			row;
	int			col;
	int			offset;
	char		buffer[MEM_SIZE * 4 + 100];

	row = 0;
	offset = 0;
	write(1, "\n", 1); // XXX enlever
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

/*
** Recupere un octet de la memoire et renvoie sa valeur avec le bon endianisme.
*/

int				mem_get_int(t_data *data, t_proc *process, int offset)
{

	unsigned char	tmp[4];

	tmp[0] = mem_get_byte(data, process, offset + 3);
	tmp[1] = mem_get_byte(data, process, offset + 2);
	tmp[2] = mem_get_byte(data, process, offset + 1);
	tmp[3] = mem_get_byte(data, process, offset + 0);
	return (*(int*)tmp);
}

/*
** Bon la c'est comme au-dessus mais ca renvoie un short.
*/

int				mem_get_short_int(t_data *data, t_proc *process, int offset)
{

	unsigned char	tmp[2];

	tmp[0] = mem_get_byte(data, process, offset + 1);
	tmp[1] = mem_get_byte(data, process, offset + 0);
	return ((int)(*(short int*)tmp));
}

/*
** Ici on set un int (4 octets de la VM). Tout comme au dessus on change
** l'endianisme avant de l'ecrire.
*/

void			mem_set_int(t_data *data, t_proc *process, int offset, int value)
{
	ft_printf("mem_set_int verbosity = %i ", data->args->verbosity);
	mem_set_byte(data, process, offset, (unsigned char)((value >> 24) & 0xff));
	ft_printf("on a set l'octet 1 verbosity = %i", data->args->verbosity);
	mem_set_byte(data, process, offset + 1, (unsigned char)((value >> 16) & 0xff));
	ft_printf("on a set l'octet 2 verbosity = %i", data->args->verbosity);
	mem_set_byte(data, process, offset + 2, (unsigned char)((value >> 8) & 0xff));
	ft_printf("on a set l'octet 3 verbosity = %i", data->args->verbosity);
	mem_set_byte(data, process, offset + 3, (unsigned char)(value & 0xff));
	ft_printf("mem_set_int est fini, verbosity = %i ", data->args->verbosity);
}
