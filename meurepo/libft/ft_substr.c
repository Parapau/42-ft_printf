/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:06:41 by pafranco          #+#    #+#             */
/*   Updated: 2024/06/25 17:21:33 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (ft_strlen(s) < (int)start)
		len = 0;
	else if (ft_strlen(s + start) < (int)len)
		len = ft_strlen(s + start);
	ptr = ft_calloc(sizeof(char), len + 1);
	if (!ptr)
		return (0);
	if (len)
		ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}
