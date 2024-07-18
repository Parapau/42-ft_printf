/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:00:55 by pafranco          #+#    #+#             */
/*   Updated: 2024/06/25 17:21:11 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;
	int		ret;

	if (!src || !dst)
		return (0);
	index = 0;
	ret = ft_strlen((char *)src);
	while (index + 1 < size && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	if (size > index)
		dst[index] = 0;
	return (ret);
}
