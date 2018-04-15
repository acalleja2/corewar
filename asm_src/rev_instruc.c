/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_instruc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:49:59 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/15 18:42:44 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	rev_instruc(int size, int fd)
{
	write(fd, ((char*)&(size)) + 3, 1);
	write(fd, ((char*)&(size)) + 2, 1);
	write(fd, ((char*)&(size)) + 1, 1);
	write(fd, ((char*)&(size)), 1);
}