/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:11:27 by pafranco          #+#    #+#             */
/*   Updated: 2024/07/19 00:02:00 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	print_char(t_flags *flag, char c)
{
	char	*str;
	char	*extra;

	str = ft_calloc(1, 2);
	if (!str)
		return ;
	if (c)
		*str = c;
	else
		*str = 1;
	extra = ft_strdup(str);
	free(str);
	final_print(str, flag);
	free(extra);
}

void	print_str(t_flags *f, char *s)
{
	char	*extra;
	char	*extraaa;

	if (!s)
	{
		extra = ft_strdup("(null)");
		if (readflags(f->flag, 7) == 1 && ((!f->num2 && f->num <= 5)
				|| (f->num2 && f->num2 <= 5)))
		{
			f->num = f->num * (!f->num2);
			extra = ft_strdup("");
		}
	}
	else if (readflags(f->flag, 7) == 1 && (f->num < ft_strlen(s) && !f->num2))
		extra = ft_substr(s, 0, (f->num));
	else if (readflags(f->flag, 7) == 1 && f->num2 != 0
		&& f->num2 < ft_strlen(s))
		extra = ft_substr(s, 0, (f->num2));
	else
		extra = s;
	extraaa = ft_strdup(extra);
	if (extra != s)
		free(extra);
	final_print(extra, f);
	free(extraaa);
}

void	print_int(t_flags *flag, int n, int uns)
{
	char			*num;
	char			*extra;

	if (uns && n != 0)
		num = ft_uitoa((unsigned int) n);
	else
		num = ft_itoa(n);
	if (!num)
		return ;
	extra = ft_strdup(num);
	free(num);
	final_print(num, flag);
	free (extra);
}
