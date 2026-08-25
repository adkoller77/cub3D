/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:02:13 by tilogie           #+#    #+#             */
/*   Updated: 2025/02/06 17:42:25 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line(char *left_line_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_line_str[i])
		return (NULL);
	while (left_line_str[i] && left_line_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_line_str[i] && left_line_str[i] != '\n')
	{
		str[i] = left_line_str[i];
		i++;
	}
	if (left_line_str[i] == '\n')
	{
		str[i] = left_line_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_left_line_str(char *left_line_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_line_str[i] && left_line_str[i] != '\n')
		i++;
	if (!left_line_str[i])
	{
		free(left_line_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_gnl_strlen(left_line_str) - i + 1));
	if (!str)
	{
		free(left_line_str);
		return (NULL);
	}
	i++;
	j = 0;
	while (left_line_str[i])
		str[j++] = left_line_str[i++];
	str[j] = '\0';
	free(left_line_str);
	return (str);
}

char	*read_fd(int fd, char *left_line_str)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_gnl_strchr(left_line_str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		left_line_str = ft_gnl_strjoin(left_line_str, buffer);
		if (!left_line_str)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (left_line_str);
}

char	*get_next_line(int fd)
{
	char		*line_str;
	static char	*left_line_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_line_str = read_fd(fd, left_line_str);
	if (!left_line_str)
		return (NULL);
	line_str = get_line(left_line_str);
	left_line_str = new_left_line_str(left_line_str);
	if (!line_str && left_line_str)
	{
		free(left_line_str);
		left_line_str = NULL;
	}
	return (line_str);
}
