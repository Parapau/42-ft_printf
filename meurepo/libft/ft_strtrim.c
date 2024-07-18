/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:30:44 by pafranco          #+#    #+#             */
/*   Updated: 2024/06/25 17:22:37 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		index;
	int		index2;
	char	*ptr;

	index = 0;
	while (s1[index] && ft_strchr(set, (int)s1[index]))
		index++;
	index2 = ft_strlen(&s1[index]);
	while (index2 && ft_strchr(set, (int)s1[index + index2 - 1]))
		index2--;
	ptr = ft_calloc(1, index2 + 1);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, &s1[index], index2 + 1);
	return (ptr);
}
