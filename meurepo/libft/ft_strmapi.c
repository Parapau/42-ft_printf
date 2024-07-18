/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:25:33 by pafranco          #+#    #+#             */
/*   Updated: 2024/06/21 18:55:38 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int		index;
	char				*ptr;

	if (!s)
		return (0);
	index = 0;
	ptr = (char *) malloc(ft_strlen((char *)s) + 1);
	if (!ptr)
		return (0);
	while (s[index])
	{
		ptr[index] = (*f)(index, s[index]);
		index++;
	}
	ptr[index] = 0;
	return (ptr);
}
