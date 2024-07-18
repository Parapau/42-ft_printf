/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:16:42 by pafranco          #+#    #+#             */
/*   Updated: 2024/06/14 18:07:10 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*aux;
	int		index;

	aux = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			aux = (char *)&s[index];
		index++;
	}
	if (!s[index] && c == 0)
		aux = (char *)&s[index];
	return (aux);
}
