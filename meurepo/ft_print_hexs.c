/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:50:23 by pafranco          #+#    #+#             */
/*   Updated: 2024/07/19 00:56:44 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

/*static char	*print_hex2(int count, unsigned int n, int low)
{
	char			*extra;
	char			*ret;
	unsigned long	num;

	extra = ft_calloc(1, count + 2);
	if (!extra)
		return (0);
	if (n == 0)
		extra[1] = '0';
	while (n)
	{
		num = (n % 16);
		n = n / 16;
		if (num > 9)
			num = num + 'A' - 10 + (32 * low);
		else
			num += '0';
		extra[count] = num;
		count--;
	}
	ret = ft_strdup(&extra[1]);
	free(extra);
	return (ret);
}*/

void	print_hex(t_flags *flag, unsigned int n, int low)
{
	char			*ret;
	int				count;
	unsigned long	num;
	char			*extra;

	num = n;
	count = 0;
	while (num)
	{
		count++;
		num /= 16;
	}
	ret = ft_calloc(1, count + 1 + n == 0);
	if (!ret)
	{
		flag->count = -1;
		return ;
	}
	if (n == 0)
		ret[0] = '0';
	while (n != 0)
	{
		ret[--count] = n % 16 + '0';
		if (!ft_isdigit(ret[count]))
			ret[count] = n % 16 + 'A' - 10  + (32 * low);
		n /= 16;
	}
//	free(ret);
//	ret = 0;
//	ret = print_hex2(count, n, low);
	if (ret)
	{
		extra = ft_strdup(ret);
		free(ret);
		ret = 0;
		final_print(extra, flag);
		free(extra);
	}
}

static char	*print_long_hex2(int count, unsigned long n, int low)
{
	char			*extra;
	char			*ret;
	unsigned long	num;

	extra = ft_calloc(1, count);
	if (!extra)
		return (0);
	if (n == 0)
		extra[1] = '0';
	while (n)
	{
		num = (n % 16);
		n = n / 16;
		if (num > 9)
			num = num + 'A' - 10 + (32 * low);
		else
			num += '0';
		extra[count] = num;
		count--;
	}
	ret = ft_strdup(extra + 1);
	free(extra);
	return (ret);
}

static void	print_long_hex(t_flags *flag, unsigned long n, int low)
{
	char			*ret;
	int				count;
	unsigned long	num;

	num = n;
	count = 0;
	while (num)
	{
		count++;
		num /= 16;
	}
	ret = print_long_hex2(count, n, low);
	if (ret)
	{
		final_print(ret, flag);
		free(ret);
	}
}

void	print_ptr(t_flags *flag, void *p)
{
	if (!p)
	{
		print_str(flag, "(nil)");
		return ;
	}
	flag->flag = (flag->flag * 10) + 2;
	print_long_hex(flag, (unsigned long) p, 1);
}
