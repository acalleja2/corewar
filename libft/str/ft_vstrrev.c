/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vstrrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:13:43 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/06 17:13:44 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vstrrev(char *str)
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
}
