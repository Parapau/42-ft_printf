/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:03:55 by pafranco          #+#    #+#             */
/*   Updated: 2024/06/20 14:34:34 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int		res;

	res = n % 10;
	n = n / 10;
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (res < 0)
	{
		res = -res;
		if (n == 0)
			write(fd, "-", 1);
	}
	res += 48;
	if (n > 0)
		ft_putnbr_fd(n, fd);
	write(fd, &res, 1);
}
