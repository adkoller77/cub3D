/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:01:20 by tilogie           #+#    #+#             */
/*   Updated: 2025/01/10 11:40:59 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	need_split(const char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

int	split_count(const char *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (!need_split(s[i], c) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (need_split(s[i], c))
			in_word = 0;
		i++;
	}
	return (count);
}

char	*ft_strndup(const char *src, int nb)
{
	char	*dup;
	int		i;

	dup = (char *)malloc(sizeof(char) * (nb + 1));
	if (!dup)
		return (0);
	i = 0;
	while (i < nb && src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	*ft_free(char **array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int			i;
	const char	*str_start;
	char		**array;

	array = (char **)malloc(sizeof(char *) * (split_count(s, c) + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (need_split(*s, c) && *s)
			s++;
		if (*s)
		{
			str_start = s;
			while (*s && !need_split(*s, c))
				s++;
			array[i] = ft_strndup(str_start, s - str_start);
			if (!array[i])
				return (ft_free(array, i));
			i++;
		}
	}
	array[i] = NULL;
	return (array);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	char	*str = argv[1];
	char	charset = argv[2][0];
	char	**words = ft_split(str, charset);

	if (words)
	{
		for (int i = 0; words[i] != NULL; i++)
		{
			printf("%s\n", words[i]);
			free(words[i]);
		}
		free(words);
	}
	return (0);
}
*/
