/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:02:57 by tilogie           #+#    #+#             */
/*   Updated: 2025/02/06 17:32:56 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

char	*ft_gnl_strjoin(char *left_line_str, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_line_str)
	{
		left_line_str = (char *)malloc(1 * sizeof(char));
		left_line_str[0] = '\0';
	}
	if (!left_line_str || !buffer)
		return (NULL);
	str = malloc(sizeof(char)
			* ((ft_strlen(left_line_str) + ft_strlen(buffer)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_line_str)
		while (left_line_str[++i] != '\0')
			str[i] = left_line_str[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(left_line_str) + ft_strlen(buffer)] = '\0';
	free(left_line_str);
	return (str);
}
