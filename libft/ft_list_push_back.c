/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 20:52:36 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/15 15:05:51 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void const *content,
		size_t content_size)
{
	t_list *element;

	element = *begin_list;
	if (element == NULL)
	{
		element = ft_lstnew(content, content_size);
		*begin_list = element;
		return ;
	}
	while (element->next != NULL)
	{
		element = element->next;
	}
	element->next = ft_lstnew(content, content_size);
}
