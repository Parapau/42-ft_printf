/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:23:42 by pafranco          #+#    #+#             */
/*   Updated: 2024/06/20 15:01:55 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*clear(t_list **og, void (*del)(void *))
{
	ft_lstclear(og, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lstog;

	lstog = 0;
	while (lst && f && del)
	{
		if (!lstog)
		{
			lst2 = ft_lstnew(f(lst->content));
			lstog = lst2;
		}
		else
		{
			lst1 = ft_lstnew(f(lst->content));
			ft_lstadd_back(&lst2, lst1);
			lst2 = lst1;
		}
		if (!lst2)
			return (clear(&lstog, del));
		lst = lst->next;
	}
	return (lstog);
}
