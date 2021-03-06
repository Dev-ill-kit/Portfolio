/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <ctora@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:18:25 by student           #+#    #+#             */
/*   Updated: 2020/05/04 13:18:26 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*list;
	t_list		*new;
	t_list		*old;

	if (!lst || !f)
	{
		return (NULL);
	}
	list = ft_lstnew((*f)(lst->content));
	if (!list)
		return (NULL);
	new = list;
	old = lst->next;
	while (old)
	{
		new->next = ft_lstnew((*f)(old->content));
		if (!new)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		new = new->next;
		old = old->next;
	}
	return (list);
}
