/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:40:40 by adnajja           #+#    #+#             */
/*   Updated: 2026/09/01 16:40:43 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (game->mlx.mlx == NULL)
		return (print_error("Failed to initialize MiniLibX"));
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIDTH, HEIGHT, "cub3D");
	if (game->mlx.win == NULL)
		return (print_error("Failed to create window"));
	game->mlx.img = mlx_new_image(game->mlx.mlx, WIDTH, HEIGHT);
	if (game->mlx.img == NULL)
		return (print_error("Failed to create image buffer"));
	game->mlx.addr = mlx_get_data_addr(game->mlx.img, &game->mlx.bpp,
			&game->mlx.line_len, &game->mlx.endian);
	if (game->mlx.addr == NULL)
		return (print_error("Failed to get image data address"));
	return (0);
}

void	free_mlx(t_game *game)
{
	if (game->mlx.mlx == NULL)
		return ;
	if (game->mlx.img)
		mlx_destroy_image(game->mlx.mlx, game->mlx.img);
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	mlx_destroy_display(game->mlx.mlx);
	free(game->mlx.mlx);
	game->mlx.img = NULL;
	game->mlx.win = NULL;
	game->mlx.mlx = NULL;
}
