/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:02:31 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/30 21:07:52 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *tmp, int i)
{
	char	*new;
	int		k;
	int		len;

	k = 0;
	len = ft_strlen(tmp) - i;
	new = (char *)malloc(sizeof(char) * len + 1);
	while (k < len)
	{
		new[k] = tmp[i];
		i++;
		k++;
	}
	new[k] = '\0';
	return (new);
}
