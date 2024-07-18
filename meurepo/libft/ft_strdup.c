/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:55:42 by pafranco          #+#    #+#             */
/*   Updated: 2024/07/11 17:09:29 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *n)
{
	char	*ptr;
	int		index;

	index = ft_strlen(n) + 1;
	ptr = (char *) ft_calloc(1, sizeof(char) * index);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, n, index);
	return (ptr);
}
