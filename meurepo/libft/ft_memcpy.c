/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:54:23 by pafranco          #+#    #+#             */
/*   Updated: 2024/06/14 15:28:01 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*array;

	index = 0;
	array = (unsigned char *) dest;
	while (index < n)
	{
		array[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dest);
}
