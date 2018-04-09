/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 07:05:38 by acalleja          #+#    #+#             */
/*   Updated: 2017/12/09 21:55:55 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		int_len(long long n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

static char		*alloc_tab(void)
{
	char	*tab;
	int		i;
	int		j;

	tab = (char *)malloc(sizeof(char) * 17);
	i = -1;
	while (i++ < 9)
		tab[i] = 48 + i;
	j = 'a';
	i--;
	while (i++ < 16)
		tab[i] = j++;
	tab[16] = '\0';
	return (tab);
}

char			*ft_lltoa_base(long long n, int base)
{
	char	*str;
	int		len;
	char	*tab;

	tab = alloc_tab();
	if (base == 10)
		return (ft_lltoa(n));
	if (n == 0)
		return ("0");
	len = int_len(n, base);
	if (n < 0)
		n = -n;
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	while (n)
	{
		str[len - 1] = tab[n % base];
		n /= base;
		len--;
	}
	free(tab);
	return (str);
}
