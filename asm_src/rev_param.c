/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 16:44:37 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/15 19:18:53 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	rev_param(int nb_octet, int value, int fd)
{
	printf("value = %d, nb_octet = %d\n", value, nb_octet);
	while (nb_octet)
	{
		write(fd, (char *)&value + nb_octet - 1, 1);
		nb_octet--;
	}
}
