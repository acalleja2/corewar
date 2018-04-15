#include "corewar.h"

void		ins_live(t_proc *process, t_data *data)
{
	int				id;
	t_champion		*champion;

	if (!process->instruction_started)
	{
		process->time_to_wait = 10 - 1;
		process->instruction_started = TRUE;
		return ;
	}
	process->instruction_started = FALSE;
	process->live += 1;
	process->pc += 5;
	id = mem_get_int(data, process, 1);
	champion = get_champion_by_id(data->champs, id);
	if (champion == NULL)
		return ;
	champion->last_seen_alive = data->mem->cycle;
	if (data->args->verbosity & V_LIVES)
		ft_printf("A process claimed a live for player %i (%s)\n", champion->id, champion->name);
}
