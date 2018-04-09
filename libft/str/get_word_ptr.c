/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 17:37:44 by florenzo          #+#    #+#             */
/*   Updated: 2018/02/17 17:37:44 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Renvoie un pointeur sur le n-ieme mot dans la chaine
** s'il n'y en a pas renvoie NULL
*/

char		*get_word_ptr(const char *str, int n)
{
	int		words;

	if (NULL == str)
		return (NULL);
	words = -1;
	while ('\0' != *str)
	{
		while (ft_iswhitespace(*str))
			str += 1;
		if ('\0' != *str)
		{
			words += 1;
			if (words == n)
				return ((char*)str);
			while ('\0' != *str && !ft_iswhitespace(*str))
				str += 1;
		}
	}
	return (NULL);
}
