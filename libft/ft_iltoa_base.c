/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lonltoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:45:16 by acalleja          #+#    #+#             */
/*   Updated: 2017/12/18 11:15:17 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define ABS(x) ((x) < 0 ? -(x) : (x))

static void		ft_convert(char *res, long nbr, int base, int *i)
{
	char	*nbrbase;

	nbrbase = ft_strdup("0123456789abcdef");
	if (nbr >= base || nbr <= -base)
		ft_convert(res, nbr / base, base, i);
	res[(*i)++] = nbrbase[ABS(nbr % base)];
	free(nbrbase);
}

char			*ft_iltoa_base(long nbr, int base)
{
	char	*res;
	int		i;

	i = 0;
	if (!(res = (char *)malloc(sizeof(char) * 35)))
		return (0);
	if (base == 10 && nbr < 0)
		res[i++] = '-';
	ft_convert(res, nbr, base, &i);
	res[i] = '\0';
	return (res);
}
