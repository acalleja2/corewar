#include "corewar.h"

int			ocp_get_param1(t_data *data, t_proc *process, int offset, int *var)
{
	int		ocp;

	ocp = mem_get_byte(data, process, 1);
	/* ft_printf("Getting param 1, ocp is %x (%#.8b), param is a ", ocp, ocp); */
	if (((ocp >> 6) & 1) && ((ocp >> 6) & 2))
	{
		*var = mem_get_short_int(data, process, offset);
		/* ft_printf("index (2 bytes)\n"); */
		return (2);
	}
	else if ((ocp >> 6) & 1)
	{
		*var = mem_get_byte(data, process, offset);
		/* ft_printf("register (1 byte)\n"); */
		return (1);
	}
	else if ((ocp >> 6) & 2)
	{
		*var = mem_get_int(data, process, offset);
		/* ft_printf("direct (4 bytes)\n"); */
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
	/* ft_printf("Getting param 2, ocp is %x (%#.8b), param is a ", ocp, ocp); */
	if (((ocp >> 4) & 1) && ((ocp >> 4) & 2))
	{
		*var = mem_get_short_int(data, process, offset);
		/* ft_printf("index (2 bytes)\n"); */
		return (2);
	}
	else if ((ocp >> 4) & 1)
	{
		*var = mem_get_byte(data, process, offset);
		/* ft_printf("register (1 byte)\n"); */
		return (1);
	}
	else if ((ocp >> 4) & 2)
	{
		*var = mem_get_int(data, process, offset);
		/* ft_printf("direct (4 bytes)\n"); */
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
	/* ft_printf("Getting param 3, ocp is %x (%#.8b), param is a ", ocp, ocp); */
	if (((ocp >> 2) & 1) && ((ocp >> 2) & 2))
	{
		*var = mem_get_short_int(data, process, offset);
		/* ft_printf("index (2 bytes)\n"); */
		return (2);
	}
	else if ((ocp >> 2) & 1)
	{
		*var = mem_get_byte(data, process, offset);
		/* ft_printf("register (1 byte)\n"); */
		return (1);
	}
	else if ((ocp >> 2) & 2)
	{
		*var = mem_get_int(data, process, offset);
		/* ft_printf("direct (4 bytes)\n"); */
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
	/* ft_printf("Getting param 1, ocp is %x (%#.8b), param is a ", ocp, ocp); */
	if (((ocp >> 6) & 1) && ((ocp >> 6) & 2))
	{
		*var = mem_get_short_int(data, process, offset);
		/* ft_printf("index (2 bytes)\n"); */
		return (2);
	}
	else if ((ocp >> 6) & 1)
	{
		*var = mem_get_byte(data, process, offset);
		/* ft_printf("register (1 byte)\n"); */
		return (1);
	}
	else if ((ocp >> 6) & 2)
	{
		*var = mem_get_short_int(data, process, offset);
		/* ft_printf("indirect (2 bytes)\n"); */
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
	/* ft_printf("Getting param 2, ocp is %x (%#.8b), param is a ", ocp, ocp); */
	if (((ocp >> 4) & 1) && ((ocp >> 4) & 2))
	{
		*var = mem_get_short_int(data, process, offset);
		/* ft_printf("index (2 bytes)\n"); */
		return (2);
	}
	else if ((ocp >> 4) & 1)
	{
		*var = mem_get_byte(data, process, offset);
		/* ft_printf("register (1 byte)\n"); */
		return (1);
	}
	else if ((ocp >> 4) & 2)
	{
		*var = mem_get_short_int(data, process, offset);
		/* ft_printf("indirect (2 bytes)\n"); */
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
	/* ft_printf("Getting param 3, ocp is %x (%#.8b), param is a ", ocp, ocp); */
	if (((ocp >> 2) & 1) && ((ocp >> 2) & 2))
	{
		*var = mem_get_short_int(data, process, offset);
		/* ft_printf("index (2 bytes)\n"); */
		return (2);
	}
	else if ((ocp >> 2) & 1)
	{
		*var = mem_get_byte(data, process, offset);
		/* ft_printf("register (1 byte)\n"); */
		return (1);
	}
	else if ((ocp >> 2) & 2)
	{
		*var = mem_get_short_int(data, process, offset);
		/* ft_printf("indirect (2 bytes)\n"); */
		return (2);
	}
	else
		*var = 0;
	return (0);
}
