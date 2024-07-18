/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:53:12 by pafranco          #+#    #+#             */
/*   Updated: 2024/07/15 17:52:40 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

typedef struct flags
{
	char	type;
	int		flag;
	int		num;
	int		num2;
	int		count;
}				t_flags;

int		ft_printf(char *str, ...);

void	print_ptr(t_flags *flag, void *p);
void	print_hex(t_flags *flag, unsigned int n, int low);
void	print_str(t_flags *flag, char *str);
void	print_char(t_flags *flag, char c);
void	print_int(t_flags *flag, int n, int uns);
void	final_print(char *str, t_flags *flag);

void	asign(char **o, t_flags *fl, int f, char *(*i)(int, char *, t_flags *));

char	*ft_uitoa(unsigned int n);

int		isflag(char c, int f);
t_flags	*createflag(char **str, char a, int c);
int		readflags(int flags, int f);
void	free_flag(t_flags *flag);

#endif
