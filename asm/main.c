/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:24:23 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/12 14:12:10 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		print_usage(void)
{
	ft_printf("Usage: ./asm [FILE.s]\n");
	return (0);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_label		*lab;
	t_instru	*ins;

	lab = NULL;
	ins = NULL;
	if (argc != 2)
		return (print_usage());
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (print_usage());
	line_reader(fd, &lab, &ins);
	return (0);
}
