/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:19:34 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/13 19:01:32 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	create_cor(char *file, t_instru *ins, header_t *head)
{
	int		fd;
	char	*name;

	name = ft_strjoin(file, ".cor");
	ft_printf("Writing output program to %s\n", name);
	fd = open(name, O_CREAT | O_RDWR, 0666);
	printf("magic = %d, name = %s, comment = %s\n", head->magic, head->prog_name, head->comment);
	write(fd, head, sizeof(header_t));
}
