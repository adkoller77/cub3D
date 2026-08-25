#include "cub3d.h"
#include <fcntl.h>
#include <X11/X.h>

void	free_map(char **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	free_textures(game);
	free_map(game->map.grid, game->map.size);
	while (i < 4)
	{
		if (game->map.texture_path[i])
			free(game->map.texture_path[i]);
		i++;
	}
}

void	init_game(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->map.floor_color[0] = -1;
	game->map.floor_color[1] = -1;
	game->map.floor_color[2] = -1;
	game->map.ceil_color[0] = -1;
	game->map.ceil_color[1] = -1;
	game->map.ceil_color[2] = -1;
}

static int	check_args(int ac, char **av)
{
	char	*c;
	int		fd;

	if (ac != 2)
		return (print_error("Usage: ./cub3D <map>.cub"), -1);
	c = ft_strrchr(av[1], '.');
	if (c == NULL)
		return (print_error("Missing file extension"), -1);
	if (ft_strcmp(c + 1, "cub"))
		return (print_error("File must have .cub extension"), -1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (print_error("Cannot open map file"), -1);
	return (fd);
}

int	main(int ac, char **av)
{
	int		fd;
	t_game	game;

	fd = check_args(ac, av);
	if (fd == -1)
		return (1);
	init_game(&game);
	if (read_cub(fd, &game) == -1)
		return (close(fd), free_game(&game), 1);
	if (validate_map(&game) == -1)
		return (free_game(&game), 1);
	dir_player(&game);
	if (init_mlx(&game) == -1)
		return (free_game(&game), 1);
	if (load_textures(&game) == -1)
		return (free_game(&game), 1);
	mlx_loop_hook(game.mlx.mlx, render, &game);
	mlx_hook(game.mlx.win, DestroyNotify, 0, close_window, &game);
	mlx_hook(game.mlx.win, KeyPress, KeyPressMask, key_press, &game);
	mlx_hook(game.mlx.win, KeyRelease, KeyReleaseMask, key_release, &game);
	mlx_loop(game.mlx.mlx);
	free_game(&game);
	return (0);
}
