/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:31:22 by pafranco          #+#    #+#             */
/*   Updated: 2024/06/14 20:34:16 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index1;
	size_t	index2;
	char	*result;

	if (!*little)
		return ((char *)big);
	index1 = 0;
	result = 0;
	while (big[index1] && !result && index1 < len)
	{
		index2 = 0;
		while (big[index1 + index2] == little[index2] && index1 + index2 < len)
		{
			if (!little[index2 + 1])
				return ((char *)&big[index1]);
			index2++;
		}
		index1++;
	}
	return (0);
}
