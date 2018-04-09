/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 02:15:31 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/13 05:42:38 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *elem;

	elem = *alst;
	while (elem)
	{
		del(elem->content, elem->content_size);
		free(elem);
		elem = elem->next;
	}
	*alst = NULL;
}
