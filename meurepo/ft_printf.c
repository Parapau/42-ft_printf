/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:28:36 by pafranco          #+#    #+#             */
/*   Updated: 2024/07/18 18:47:48 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

static void	print_sort(t_flags *flag, va_list args)
{
	if (flag->type == 'c')
		print_char(flag, va_arg(args, int));
	else if (flag->type == 's')
		print_str(flag, va_arg(args, char *));
	else if (flag->type == 'p')
		print_ptr(flag, va_arg(args, void *));
	else if (flag->type == 'd')
		print_int(flag, va_arg(args, int), 0);
	else if (flag->type == 'i')
		print_int(flag, va_arg(args, int), 0);
	else if (flag->type == 'u')
		print_int(flag, va_arg(args, int), 1);
	else if (flag->type == 'x')
		print_hex(flag, va_arg(args, unsigned long), 1);
	else if (flag->type == 'X')
		print_hex(flag, va_arg(args, unsigned long), 0);
}

static int	flag_found(t_flags **flag, char **str, char *extra, va_list args)
{
	int		count;

	count = 0;
	if (**str == '%')
	{
		extra = *str;
		*flag = createflag (str, 0, 0);
		if ((*flag)->type == '%')
		{
			ft_putchar_fd('%', 1);
			count++;
		}
		else if ((*flag)->type)
			print_sort(*flag, args);
		else
		{
			*str = extra;
			ft_putchar_fd('%', 1);
		}
		if ((*flag)->count)
			count += (*flag)->count;
	}
	return (count);
}

int	ft_printf(char *str, ...)
{
	int			count;
	t_flags		*flag;
	va_list		args;

	flag = 0;
	count = 0;
	va_start (args, str);
	while (*str && count >= 0)
	{
		if (*str == '%')
			count += flag_found(&flag, &str, 0, args);
		else
			count += write(1, str, 1);
		if (flag != 0 && flag->count < 0)
			count = flag->count;
		str++;
		if (flag != 0)
		{
			free(flag);
			flag = 0;
		}
	}
	va_end(args);
	return (count);
}
