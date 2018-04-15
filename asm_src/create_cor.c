/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:19:34 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/15 19:17:12 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	create_cor(char *file, t_instru *ins, header_t *head)
{
	int			fd;
	char		*name;
	int			size;
	t_instru	*tmp;

	tmp = ins;
	name = ft_strjoin(file, ".cor");
	ft_printf("Writing output program to %s\n", name);
	fd = open(name, O_CREAT | O_RDWR, 0666);
	size = count_size_tot(tmp);
	rev_magic(head, fd);
	write(fd, head->prog_name, PROG_NAME_LENGTH);
	add_empty_oct(4, fd);
	rev_instruc(size, fd);
	write(fd, head->comment, COMMENT_LENGTH);
	add_empty_oct(4, fd);
	print_param_fd(ins, fd);
}
