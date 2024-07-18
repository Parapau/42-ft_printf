/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:42:20 by pafranco          #+#    #+#             */
/*   Updated: 2024/06/18 14:43:02 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			index;

	if (dest < src)
	{
		index = 0;
		while (index < n)
		{
			((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
			index++;
		}
	}
	else
	{
		index = n;
		while (index > 0)
		{
			index--;
			((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	*a = "abcdefgha";
	char	*b = "zyxwvutsz";
	char	*n = "\n";

	write (1, a, 10);
	write(1, n, 1);
	write (1, b, 10);
	write(1, n, 1);
	ft_memmove((void *)b, (void *)a, 3);
	write (1, b, 10);
	write(1, n, 1);
	ft_memmove(a, a + 5, 1);
	write (1, a, 10);
	write(1, n, 1);
	ft_memmove(a + 3, a, 2);
	write(1, a, 10);
	write(1, n, 1);
}*/
