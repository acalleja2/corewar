/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:05:21 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/13 06:11:56 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_rec_fd(int n, int fd)
{
	if (n < 10)
	{
		n = n + '0';
		write(fd, &n, 1);
	}
	else
	{
		ft_rec_fd(n / 10, fd);
		n = n % 10;
		n = n + '0';
		write(fd, &n, 1);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
	{
		ft_rec_fd(n, fd);
	}
	else
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		else
		{
			write(fd, "-", 1);
			ft_rec_fd(-n, fd);
		}
	}
}
