#include "corewar.h"

void		ins_live(t_proc *process, t_data *data)
{
	unsigned char	tmp[4];
	int				id;
	t_champion		*champion;

	tmp[0] = mem_get_byte(mem, process, 4);
	tmp[1] = mem_get_byte(mem, process, 3);
	tmp[2] = mem_get_byte(mem, process, 2);
	tmp[3] = mem_get_byte(mem, process, 1);
	process->live += 1;
	process->time_to_wait = 10;
	process->pc += 5;
	id = *(int*)tmp;
	champion = get_champion_by_id(champs, id);
	if (champion == NULL)
		return ;
	champion->last_seen_alive = mem->cycle;
}
