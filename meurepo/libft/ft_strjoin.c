/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:02:38 by pafranco          #+#    #+#             */
/*   Updated: 2024/06/25 17:22:33 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*pt;

	pt = ft_calloc(1, ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!pt)
		return (0);
	ft_strlcpy(pt, s1, ft_strlen((char *) s1) + 1);
	ft_strlcpy(pt + ft_strlen((char *)s1), s2, ft_strlen((char *)s2) + 1);
	return (pt);
}
