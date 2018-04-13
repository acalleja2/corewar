/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_magic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:30:16 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/13 19:43:28 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	rev_magic(header_t *head, int fd)
{
	write(fd, ((char*)&(head->magic)) + 3, 1);
	write(fd, ((char*)&(head->magic)) + 2, 1);
	write(fd, ((char*)&(head->magic)) + 1, 1);
	write(fd, ((char*)&(head->magic)), 1);
}
