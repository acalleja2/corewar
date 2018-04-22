#include "corewar.h"

/*
** Toutes ces fonction ont le meme role, elles renvoient le param n,
** la difference est le n et le type de param, direct ou indirect.
*/

int			ocp_get_param1(t_data *data, t_proc *process, int offset, int *var)
{
	int		ocp;

	ocp = mem_get_byte(data, process, 1);
	if (((ocp >> 6) & 1) && ((ocp >> 6) & 2))
	{
		*var = mem_get_short_int(data, process, offset);
		return (2);
	}
	else if ((ocp >> 6) & 1)
	{
		*var = mem_get_byte(data, process, offset);
		return (1);
	}
	else if ((ocp >> 6) & 2)
	{
		*var = mem_get_int(data, process, offset);
		return (4);
	}
	else
		*var = 0;
	return (0);
}

int			ocp_get_param2(t_data *data, t_proc *process, int offset, int *var)
{
	int		ocp;

	ocp = mem_get_byte(data, process, 1);
	if (((ocp >> 4) & 1) && ((ocp >> 4) & 2))
	{
		*var = mem_get_short_int(data, process, offset);
		return (2);
	}
	else if ((ocp >> 4) & 1)
	{
		*var = mem_get_byte(data, process, offset);
		return (1);
	}
	else if ((ocp >> 4) & 2)
	{
		*var = mem_get_int(data, process, offset);
		return (4);
	}
	else
		*var = 0;
	return (0);
}

int			ocp_get_param3(t_data *data, t_proc *process, int offset, int *var)
{
	int		ocp;

	ocp = mem_get_byte(data, process, 1);
	if (((ocp >> 2) & 1) && ((ocp >> 2) & 2))
	{
		*var = mem_get_short_int(data, process, offset);
		return (2);
	}
	else if ((ocp >> 2) & 1)
	{
		*var = mem_get_byte(data, process, offset);
		return (1);
	}
	else if ((ocp >> 2) & 2)
	{
		*var = mem_get_int(data, process, offset);
		return (4);
	}
	else
		*var = 0;
	return (0);
}

int			ocp_get_param1_ind(t_data *data, t_proc *process, int offset, int *var)
{
	int		ocp;

	ocp = mem_get_byte(data, process, 1);
	if (((ocp >> 6) & 1) && ((ocp >> 6) & 2))
	{
		*var = mem_get_short_int(data, process, offset);
		return (2);
	}
	else if ((ocp >> 6) & 1)
	{
		*var = mem_get_byte(data, process, offset);
		return (1);
	}
	else if ((ocp >> 6) & 2)
	{
		*var = mem_get_short_int(data, process, offset);
		return (2);
	}
	else
		*var = 0;
	return (0);
}

int			ocp_get_param2_ind(t_data *data, t_proc *process, int offset, int *var)
{
	int		ocp;

	ocp = mem_get_byte(data, process, 1);
	if (((ocp >> 4) & 1) && ((ocp >> 4) & 2))
	{
		*var = mem_get_short_int(data, process, offset);
		return (2);
	}
	else if ((ocp >> 4) & 1)
	{
		*var = mem_get_byte(data, process, offset);
		return (1);
	}
	else if ((ocp >> 4) & 2)
	{
		*var = mem_get_short_int(data, process, offset);
		return (2);
	}
	else
		*var = 0;
	return (0);
}

int			ocp_get_param3_ind(t_data *data, t_proc *process, int offset, int *var)
{
	int		ocp;

	ocp = mem_get_byte(data, process, 1);
	if (((ocp >> 2) & 1) && ((ocp >> 2) & 2))
	{
		*var = mem_get_short_int(data, process, offset);
		return (2);
	}
	else if ((ocp >> 2) & 1)
	{
		*var = mem_get_byte(data, process, offset);
		return (1);
	}
	else if ((ocp >> 2) & 2)
	{
		*var = mem_get_short_int(data, process, offset);
		return (2);
	}
	else
		*var = 0;
	return (0);
}
