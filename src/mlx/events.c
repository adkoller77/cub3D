/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:59:46 by adnajja           #+#    #+#             */
/*   Updated: 2026/08/19 22:42:00 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_game *game)
{
	free_game(game);
	exit(0);
}

int	render(t_game *game)
{
	handle_input(game);
	raycast(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
		game->mlx.img, 0, 0);
	return (0);
}
