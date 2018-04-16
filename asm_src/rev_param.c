/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 16:44:37 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/16 13:18:41 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	rev_param(int nb_octet, int value, int fd)
{
	while (nb_octet)
	{
		write(fd, (char *)&value + nb_octet - 1, 1);
		nb_octet--;
	}
}
