/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 22:49:24 by adnajja           #+#    #+#             */
/*   Updated: 2026/08/19 18:56:30 by adnajja          ###   ########.fr       */
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
