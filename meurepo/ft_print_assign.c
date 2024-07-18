/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_assign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:24:27 by pafranco          #+#    #+#             */
/*   Updated: 2024/07/19 01:31:32 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static char	*modstr(int f, char *str, t_flags *l)
{
	char	*ex;
	char	*ret;

	ex = ft_calloc(1, 2 + (l->type == 'x' || l->type == 'X' || l->type == 'p'));
	if (!ex)
		return (0);
	if (f == 2 && (l->type == 'x' || l->type == 'X' || l->type == 'p')
		&& !(str[0] == '0' && ft_strlen(str) == 1))
	{
		if (l->type == 'p')
			l->type = 'x';
		ex[0] = '0';
		ex[1] = l->type;
	}
	else if (f == 3 && (l->type == 'd' || l->type == 'i') && ft_atoi(str) >= 0)
		ex[0] = '+';
	else if (f == 4 && (l->type == 'd' || l->type == 'i') && ft_atoi(str) >= 0)
		ex[0] = ' ';
	else
		return (free(ex), str);
	return (ret = ft_strjoin(ex, str), free(ex), ret);
}

static char	*modstrdot(int f, char *str, t_flags *fl)
{
	int		sz;
	int		m;
	char	*ex;
	char	*ret;

	m = 0;
	m += (str[0] == '-');
	str += (str[0] == '-');
	sz = ft_strlen(str);
	if (sz == 1 && str[0] == '0')
		str[0] = 0;
	if (sz < ((fl->num) * (!fl->num2)) + fl->num2 && f == 1)
	{
		ex = ft_calloc(1, (((fl->num) * (!fl->num2)) + fl->num2) + 1 + m - sz);
		if (!ex)
			return (0);
		ft_memset(ex, '0', (((fl->num) * (!fl->num2)) + fl->num2) + m - sz);
		ret = ft_strjoin(ex, str);
		if (!ret)
			return (free(ex), NULL);
		if (m)
			ret[0] = '-';
		return (free(ex), ret);
	}
	return (str -= (*(str - 1) == '-'), str);
}

static char	*modwidth(int f, char *s, t_flags *fl)
{
	char	car;
	char	*extra;
	int		sign;
	int		place;

	car = ' ';
	place = ((ft_strchr("+- ", s[0])) && f == 6 && readflags(fl->flag, 7) != 1);
	sign = ((ft_strchr("+- ", s[0])) && f == 6 && readflags(fl->flag, 7) != 1);
	if (ft_strlen(s) < fl->num)
	{
		extra = ft_calloc(fl->num - ft_strlen(&(s[place])) + 1, 1);
		if (!extra)
			return (0);
		if (f == 6 && !ft_strchr("pc", fl->type) && readflags(fl->flag, 7) != 1)
			car = '0';
		ft_memset(extra, car, fl->num - ft_strlen(&(s[place])));
		if (sign && f == 6)
			extra[0] = s[0];
		if (f == 5)
			s = ft_strjoin(&(s[place]), extra);
		else
			s = ft_strjoin(extra, &(s[place]));
		free(extra);
	}
	return (s);
}

void	asign(char **o, t_flags *fl, int f, char *(*i)(int, char *, t_flags *))
{
	char	*extra;

	extra = *o;
	*o = i(f, *o, fl);
	if (extra != *o)
		free(extra);
}

void	final_print(char *str, t_flags *fl)
{
	int		f;
	int		check;
	char	*extra;

	f = 7;
	check = 0;
	extra = ft_strdup(str);
	if (!extra)
		return ;
	while (f)
	{
		f = readflags(fl->flag, f);
		if (f >= 2 && f <= 4)
			asign(&extra, fl, f, modstr);
		else if (f == 1 && !ft_strchr("psc", fl->type))
		{
			asign(&extra, fl, f, modstrdot);
			check = 1;
		}
		else if ((f == 0 || f == 5 || f == 6) && ((check == 1 && fl->num2)
				|| (check == 0)) && fl->num)
			asign(&extra, fl, f, modwidth);
	}
	fl->count = write(1, extra, ft_strlen(extra)); 
	free(extra);
}
