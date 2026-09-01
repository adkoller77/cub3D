/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:40:40 by adnajja           #+#    #+#             */
/*   Updated: 2026/09/01 16:40:43 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_element(char *line, t_game *game)
{
	if (is_blank_line(line))
		return (0);
	if (ft_strncmp(line, "NO", 2) == 0)
		return (parse_texture(line, game, 0));
	if (ft_strncmp(line, "SO", 2) == 0)
		return (parse_texture(line, game, 1));
	if (ft_strncmp(line, "EA", 2) == 0)
		return (parse_texture(line, game, 2));
	if (ft_strncmp(line, "WE", 2) == 0)
		return (parse_texture(line, game, 3));
	if (line[0] == 'F')
		return (parse_color(line, game, 1));
	if (line[0] == 'C')
		return (parse_color(line, game, 0));
	return (-2);
}

static int	is_map_line(char c)
{
	return (c == '1' || c == '0' || c == ' '
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	read_cub(int fd, t_game *game)
{
	char	*line;
	int		ret;

	line = get_next_line(fd);
	while (line)
	{
		ret = parse_element(line, game);
		if (ret == -2 && is_map_line(line[0]))
			return (parse_map(fd, game, line));
		free(line);
		if (ret == -2)
			ret = print_error("Unknown element identifier");
		if (ret == -1)
			return (flush_gnl(fd), close(fd), -1);
		line = get_next_line(fd);
	}
	close(fd);
	if (check_elements(game) == -1)
		return (-1);
	return (0);
}
