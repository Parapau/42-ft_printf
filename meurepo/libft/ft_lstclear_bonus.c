/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:35:49 by pafranco          #+#    #+#             */
/*   Updated: 2024/06/20 13:37:35 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	while ((*lst)->next)
	{
		aux = (*lst)->next;
		del((*lst)->content);
		del((*lst)->next);
		free(*lst);
		*lst = aux;
	}
	del((*lst)->content);
	del((*lst)->next);
	free(*lst);
	*lst = 0;
}
