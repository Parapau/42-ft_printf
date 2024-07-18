/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:49:14 by pafranco          #+#    #+#             */
/*   Updated: 2024/07/08 15:28:45 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int	numsize(unsigned int n)
{
	int		count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	putnbr(unsigned int n, char *ptr)
{
	int		quo;
	int		res;

	res = n % 10;
	quo = n / 10;
	if (n == 0)
		ptr[0] = '0';
	while (numsize(n) != 0)
	{
		ptr[numsize(n) - 1] = res + 48;
		n = quo;
		res = quo % 10;
		quo /= 10;
	}
}

char	*ft_uitoa(int n)
{
	char	*ptr;

	ptr = ft_calloc(1, numsize(n) + 1 + (n <= 0));
	if (!ptr)
		return (0);
	putnbr(n, ptr);
	return (ptr);
}
