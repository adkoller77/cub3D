#include "cub3d.h"

int	load_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->mlx.tex[i].img = mlx_xpm_file_to_image(game->mlx.mlx,
				game->map.texture_path[i], &game->mlx.tex[i].width,
				&game->mlx.tex[i].height);
		if (game->mlx.tex[i].img == NULL)
			return (print_error("Failed to load texture file"));
		game->mlx.tex[i].addr = mlx_get_data_addr(game->mlx.tex[i].img,
				&game->mlx.tex[i].bpp, &game->mlx.tex[i].line_len,
				&game->mlx.tex[i].endian);
		if (game->mlx.tex[i].addr == NULL)
			return (print_error("Failed to read texture data"));
		i++;
	}
	return (0);
}

void	free_textures(t_game *game)
{
	int	i;

	if (game->mlx.mlx == NULL)
		return ;
	i = 0;
	while (i < 4)
	{
		if (game->mlx.tex[i].img)
			mlx_destroy_image(game->mlx.mlx, game->mlx.tex[i].img);
		i++;
	}
}
