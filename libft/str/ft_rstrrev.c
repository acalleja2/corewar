/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rstrrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:18:49 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/06 17:18:51 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rstrrev(char *str)
{
	int		end;
	int		pos;
	char	tmp;

	end = 0;
	while (str[end])
		end++;
	end--;
	pos = 0;
	while (pos < end)
	{
		tmp = str[pos];
		str[pos] = str[end];
		str[end] = tmp;
		pos++;
		end--;
	}
	return (str);
}
