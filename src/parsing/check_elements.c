#include "cub3d.h"

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
