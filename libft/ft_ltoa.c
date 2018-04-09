/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:53:12 by acalleja          #+#    #+#             */
/*   Updated: 2017/12/17 22:25:11 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(unsigned long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_putnbr_tab(char *str, int len, unsigned long n)
{
	str[len] = n % 10 + 48;
	n = n / 10;
	len--;
	if (n != 0)
		ft_putnbr_tab(str, len, n);
	return (str);
}

char			*ft_ltoa(unsigned long n)
{
	int		len;
	char	*str;

	len = ft_len(n);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str = ft_putnbr_tab(str, len - 1, n);
	str[len] = '\0';
	return (str);
}
