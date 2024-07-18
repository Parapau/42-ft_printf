/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:57:21 by pafranco          #+#    #+#             */
/*   Updated: 2024/06/18 18:52:29 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	car;
	unsigned char	*aux;

	car = (unsigned char) c;
	aux = (unsigned char *) s;
	index = 0;
	while (aux[index] != car && index < n)
		index++;
	if (index == n)
		return (0);
	return ((void *)&aux[index]);
}
