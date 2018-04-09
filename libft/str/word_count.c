/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 15:39:53 by florenzo          #+#    #+#             */
/*   Updated: 2018/02/17 15:39:53 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compte le nombre de mots dans la chaine
** Je pense que vous vous en doutiez :P
*/

int		word_count(const char *str)
{
	int		words;

	if (NULL == str)
		return (0);
	words = 0;
	while ('\0' != *str)
	{
		while (ft_iswhitespace(*str))
			str += 1;
		if ('\0' != *str)
		{
			words += 1;
			while ('\0' != *str && !ft_iswhitespace(*str))
				str += 1;
		}
	}
	return (words);
}
