/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:24:23 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/22 15:43:22 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		print_usage(void)
{
	ft_printf("Usage: ./asm [FILE.s]\n");
	exit(EXIT_FAILURE);
}

static void	bad_file(char *filename)
{
	ft_printf("could not open file %s\n", filename);
	perror("");
	exit(EXIT_FAILURE);
}

int			main(int argc, char **argv)
{
	int			fd;
	char		**name;
	t_label		*lab;
	t_instru	*ins;
	char		*str;

	lab = NULL;
	ins = NULL;
	if (argc != 2)
		print_usage();
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		bad_file(argv[1]);
	name = ft_strsplit(argv[1], '.');
	if (ft_strcmp(name[len_tab(name) - 1], "s"))
		print_usage();
	str = split_extend(name, len_tab(name));
	line_reader(fd, &lab, &ins, name[0]);
	free_tab(name);
	free(str);
	return (0);
}
