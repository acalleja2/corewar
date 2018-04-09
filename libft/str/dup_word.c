/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 17:33:43 by florenzo          #+#    #+#             */
/*   Updated: 2018/02/17 17:33:43 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Renvoie une copie du n-ieme mot
*/

char		*dup_word(const char *str, int n)
{
	const char	*wptr;
	int			len;

	len = 0;
	wptr = str;
	if (n != 0)
	{
		if (NULL == (wptr = get_word_ptr(str, n)))
			return (NULL);
	}
	while (len[wptr] && !ft_iswhitespace(len[wptr]))
		len += 1;
	return (ft_strsub(wptr, 0, len));
}
