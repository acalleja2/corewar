/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:58:27 by florenzo          #+#    #+#             */
/*   Updated: 2017/11/10 18:09:24 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_tls(const char *s)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (ft_iswhitespace(s[start]))
		++start;
	end = 0;
	while (s[end])
		++end;
	--end;
	while (ft_iswhitespace(s[end]) && end)
		--end;
	if (start > end)
		return (0);
	return (end - start + 1);
}

static void		ft_cpy(const char *s, char *new, size_t len)
{
	size_t	pos;
	size_t	i;

	pos = 0;
	while (ft_iswhitespace(s[pos]))
		++pos;
	i = 0;
	while (i < len)
	{
		new[i] = s[pos + i];
		++i;
	}
	new[i] = '\0';
}

char			*ft_strtrim(const char *s)
{
	char	*new;
	size_t	pos;
	size_t	len;

	if (!s)
		return (NULL);
	pos = 0;
	while (s[pos])
		++pos;
	if (!pos)
		return ((char*)s);
	len = ft_tls(s);
	if (!(new = (char*)ealloc(len + 1 * sizeof(char))))
		return (NULL);
	if (!len)
	{
		*new = '\0';
		return (new);
	}
	ft_cpy(s, new, len);
	return (new);
}
