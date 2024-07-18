/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:46:26 by pafranco          #+#    #+#             */
/*   Updated: 2024/06/21 18:47:51 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	index;

	if (!dst || !src)
		return (0);
	dstlen = ft_strlen(dst);
	index = 0;
	while (src[index] && dstlen + index + 1 < size)
	{
		dst[dstlen + index] = src[index];
		index++;
	}
	dst[index + dstlen] = 0;
	if (size > dstlen)
		return (dstlen + ft_strlen(src));
	return (size + ft_strlen(src));
}
