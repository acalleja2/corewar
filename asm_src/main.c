/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:24:23 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/16 13:20:53 by acalleja         ###   ########.fr       */
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
	char		**name;
	t_label		*lab;
	t_instru	*ins;

	lab = NULL;
	ins = NULL;
	if (argc != 2)
		return (print_usage());
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (print_usage());
	name = ft_strsplit(argv[1], '.');
	if (len_tab(name) != 2 || ft_strcmp(name[1], "s"))
	{
		free_tab(name);
		return (print_usage());
	}
	line_reader(fd, &lab, &ins, name[0]);
	free_tab(name);
	return (0);
}
