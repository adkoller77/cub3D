/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:40:40 by adnajja           #+#    #+#             */
/*   Updated: 2026/09/01 16:40:43 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_blank_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t'
			&& line[i] != '\n' && line[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

int	check_elements(t_game *game)
{
	if (!game->map.texture_path[0] || !game->map.texture_path[1]
		|| !game->map.texture_path[2] || !game->map.texture_path[3])
		return (print_error("Missing texture definition"));
	if (game->map.floor_color[0] == -1 || game->map.ceil_color[0] == -1)
		return (print_error("Missing floor or ceiling color"));
	if (game->map.grid == NULL)
		return (print_error("Missing map"));
	return (0);
}
