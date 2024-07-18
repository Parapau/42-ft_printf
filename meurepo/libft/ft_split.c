/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:58:29 by pafranco          #+#    #+#             */
/*   Updated: 2024/06/25 17:24:54 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_words(const char *s, char c)
{
	int		count;
	int		isword;
	int		index;

	count = 0;
	index = 0;
	isword = 1;
	while (s[index])
	{
		if (s[index] == c && isword == 0)
			isword = 1;
		else if (s[index] != c && isword == 1)
		{
			isword = 0;
			count++;
		}
		index++;
	}
	return (count);
}

static int	len(const char *s)
{
	int		index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

static void	lib(char **result)
{
	int		index;

	index = 0;
	while (result[index])
	{
		free(result[index]);
		index++;
	}
	free(result);
}

static int	crea(char **result, const char *s, char c, int index)
{
	char	*word;
	size_t	size;

	if (ft_strchr(s, c))
	{
		size = ft_strchr(s, c) - s + 1;
		word = (char *) malloc(size);
	}
	else
	{
		size = len(s) + 1;
		word = (char *) malloc(size);
	}
	if (!word)
	{
		lib(result);
		return (-5);
	}
	result[index] = word;
	ft_strlcpy(word, s, size);
	return ((int)(size - 1));
}

char	**ft_split(const char *s, char c)
{
	int		index;
	int		index2;
	int		temp;
	char	**result;

	index = 0;
	index2 = 0;
	result = (char **) malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (0);
	result[count_words(s, c)] = 0;
	while (s[index])
	{
		if (s[index] != c && (index == 0 || s[index - 1] == c))
		{
			temp = crea(result, &s[index], c, index2);
			if (temp == -5)
				return (result);
			index += temp;
			index2++;
		}
		else
			index++;
	}
	return (result);
}
