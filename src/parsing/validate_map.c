/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:40:40 by adnajja           #+#    #+#             */
/*   Updated: 2026/09/01 16:40:43 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pos_player(t_game *game, int i, int j, char c)
{
	if (game->player.dir != 0)
		return (print_error("Multiple player start positions"));
	game->player.player_x = j;
	game->player.player_y = i;
	game->player.dir = c;
	return (0);
}

int	check_chars_map(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < game->map.size)
	{
		j = 0;
		while (game->map.grid[i][j])
		{
			c = game->map.grid[i][j];
			if (c != '1' && c != '0' && c != ' '
				&& c != 'N' && c != 'S' && c != 'E' && c != 'W')
				return (print_error("Invalid character in map"));
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				if (pos_player(game, i, j, c) == -1)
					return (-1);
			j++;
		}
		i++;
	}
	if (game->player.dir == 0)
		return (print_error("No player start position found"));
	return (0);
}

char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * game->map.size);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < game->map.size)
	{
		copy[i] = ft_strdup(game->map.grid[i]);
		if (copy[i] == NULL)
			return (free_map(copy, i), NULL);
		i++;
	}
	return (copy);
}

int	flood_fill(char **map, int i, int j, int size)
{
	if (i < 0 || j < 0 || i >= size || j >= (int)ft_strlen(map[i]))
		return (print_error("Map is not closed"));
	if (map[i][j] == '1' || map[i][j] == 'V')
		return (0);
	if (map[i][j] == ' ')
		return (print_error("Map is not closed"));
	map[i][j] = 'V';
	if (flood_fill(map, i + 1, j, size) == -1)
		return (-1);
	if (flood_fill(map, i - 1, j, size) == -1)
		return (-1);
	if (flood_fill(map, i, j + 1, size) == -1)
		return (-1);
	if (flood_fill(map, i, j - 1, size) == -1)
		return (-1);
	return (0);
}

int	validate_map(t_game *game)
{
	char	**map_copy;

	if (check_chars_map(game) == -1)
		return (-1);
	map_copy = copy_map(game);
	if (map_copy == NULL)
		return (print_error("Memory allocation failed"));
	if (flood_fill(map_copy, game->player.player_y,
			game->player.player_x, game->map.size) == -1)
		return (free_map(map_copy, game->map.size), -1);
	free_map(map_copy, game->map.size);
	return (0);
}
