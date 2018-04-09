/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:53:12 by acalleja          #+#    #+#             */
/*   Updated: 2017/12/09 02:43:50 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(int n)
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

static char		*ft_putnbr_tab(char *str, int len, int n)
{
	str[len] = n % 10 + 48;
	n = n / 10;
	len--;
	if (n != 0)
		ft_putnbr_tab(str, len, n);
	return (str);
}

static char		*ft_exept(void)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * (9 + 3))))
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str = ft_putnbr_tab(str, 10, 147483648);
	str[11] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		str = ft_exept();
	else if (n < 0)
	{
		len = ft_len(-n);
		if (!(str = (char *)malloc(sizeof(char) * len + 2)))
			return (NULL);
		str[0] = '-';
		str = ft_putnbr_tab(str, len, -n);
		str[len + 1] = '\0';
	}
	else
	{
		len = ft_len(n);
		if (!(str = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		str = ft_putnbr_tab(str, len - 1, n);
		str[len] = '\0';
	}
	return (str);
}
