/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:37:21 by pafranco          #+#    #+#             */
/*   Updated: 2024/06/14 17:57:35 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	char	car;

	car = (char)c;
	if ((car >= '0' && car <= '9') || (car >= 'a' && car <= 'z')
		|| (car >= 'A' && car <= 'Z'))
		return (1);
	return (0);
}
