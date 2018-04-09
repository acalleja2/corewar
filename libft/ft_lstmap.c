/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 04:00:27 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/13 07:01:12 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin;
	t_list *elem;

	if (lst == NULL)
		return (NULL);
	elem = (*f)(lst);
	begin = elem;
	lst = lst->next;
	while (lst)
	{
		elem->next = (*f)(lst);
		elem = elem->next;
		lst = lst->next;
	}
	elem = NULL;
	return (begin);
}
