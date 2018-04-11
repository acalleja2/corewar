/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:36:53 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/11 13:32:53 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_strn_dup(char *s1, int n)
{
	int		i;
	char	*tab;

	i = 0;
	tab = (char *)ealloc(sizeof(char) * n + 1);
	if (tab == NULL)
		return (NULL);
	while (i < n)
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
