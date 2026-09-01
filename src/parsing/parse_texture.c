/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:40:40 by adnajja           #+#    #+#             */
/*   Updated: 2026/09/01 16:40:43 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

int	parse_texture(char *line, t_game *game, int index)
{
	int		i;
	int		fd;
	char	*modif_line;

	i = 2;
	if (line[2] != ' ')
		return (print_error("Missing space after texture identifier"));
	while (line[i] == ' ')
		i++;
	modif_line = ft_strchr(line, '\n');
	if (modif_line)
		*modif_line = '\0';
	if (line[i] == '\0')
		return (print_error("Missing texture path"));
	if (game->map.texture_path[index] != NULL)
		return (print_error("Duplicate texture definition"));
	fd = open(line + i, O_RDONLY);
	if (fd < 0)
		return (print_error("Cannot open texture file"));
	close(fd);
	game->map.texture_path[index] = ft_strdup(line + i);
	if (game->map.texture_path[index] == NULL)
		return (print_error("Memory allocation failed"));
	return (0);
}
