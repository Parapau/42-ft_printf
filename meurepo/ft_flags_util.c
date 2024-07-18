/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:17:09 by pafranco          #+#    #+#             */
/*   Updated: 2024/07/18 19:04:28 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isflag(char c, int f)
{
	if (f == 0)
	{
		if (c == '.')
			return (1);
		else if (c == '#')
			return (2);
		else if (c == '+')
			return (3);
		else if (c == ' ')
			return (4);
		else if (c == '-')
			return (5);
		else if (c == '0')
			return (6);
	}
	if (f == 1 && (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
			|| c == 'u' || c == 'x' || c == 'X' || c == '%'))
		return (c);
	else if (f == 2 && ft_isdigit(c))
		return (c);
	return (0);
}

t_flags	*createflag(char **str, char a, int c)
{
	t_flags		*f;

	(*str)++;
	a = isflag(**str, 0);
	a = isflag(**str, 2 * (!a));
	f = ft_calloc(1, sizeof(f));
	if (!f)
		return (0);
	while (a && **str)
	{
		if (a < 8 && (!f->num || a == 1))
			f->flag = f->flag * 10 + a;
		if ((f->num != 0) && a < 8 && (!f->num || a == 1))
			c = 1;
		else if (a > 8)
		{
			f->num = (((f->num * 10) + (a - '0')) * (!c)) + (f->num * c);
			f->num2 = ((f->num2 * 10) + (a - '0') * (c));
		}
		(*str)++;
		a = isflag(**str, 0);
		if (!a || ((f->num != 0) && a != 1) || f->num2 != 0)
			a = isflag(**str, 2);
	}
	return (f->type = isflag(**str, 1), f);
}

int	readflags(int flags, int f)
{
	char	*num;
	int		ret;

	ret = 0;
	num = ft_itoa(flags);
	if (!num)
		return (0);
	if (ft_strchr(num, '1') && (f == 7))
		ret = (1);
	else if (ft_strchr(num, '2') && (f == 7 || f < 2))
		ret = (2);
	else if (ft_strchr(num, '3') && (f == 7 || f < 3))
		ret = (3);
	else if (ft_strchr(num, '4') && (f == 7 || f < 3))
		ret = (4);
	else if (ft_strchr(num, '5') && (f == 7 || f < 5))
		ret = (5);
	else if (ft_strchr(num, '6') && (f == 7 || f < 5))
		ret = (6);
	free(num);
	return (ret);
}
