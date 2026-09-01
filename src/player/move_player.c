/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:40:40 by adnajja           #+#    #+#             */
/*   Updated: 2026/09/01 16:40:43 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define SPEED 0.03
#define ROT_SPEED 0.02
#define COLLISION_MARGIN 0.2

static int	is_wall(t_game *game, double x, double y)
{
	return (game->map.grid[(int)y][(int)x] == '1');
}

static double	collide_offset(double delta)
{
	if (delta > 0)
		return (COLLISION_MARGIN);
	return (-COLLISION_MARGIN);
}

static void	get_move_delta(t_game *game, char dir, double *dx, double *dy)
{
	*dx = 0;
	*dy = 0;
	if (dir == 'W')
	{
		*dx = game->player.dir_x * SPEED;
		*dy = game->player.dir_y * SPEED;
	}
	else if (dir == 'S')
	{
		*dx = -game->player.dir_x * SPEED;
		*dy = -game->player.dir_y * SPEED;
	}
	else if (dir == 'A')
	{
		*dx = game->player.dir_y * SPEED;
		*dy = -game->player.dir_x * SPEED;
	}
	else if (dir == 'D')
	{
		*dx = -game->player.dir_y * SPEED;
		*dy = game->player.dir_x * SPEED;
	}
}

void	move_player(t_game *game, char dir)
{
	double	new_x;
	double	new_y;
	double	dx;
	double	dy;

	get_move_delta(game, dir, &dx, &dy);
	new_x = game->player.pos_x + dx;
	new_y = game->player.pos_y + dy;
	if (!is_wall(game, new_x + collide_offset(dx), game->player.pos_y))
		game->player.pos_x = new_x;
	if (!is_wall(game, game->player.pos_x, new_y + collide_offset(dy)))
		game->player.pos_y = new_y;
}

void	rotate_player(t_game *game, int direction)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_r;
	double	sin_r;

	cos_r = cos(ROT_SPEED * direction);
	sin_r = sin(ROT_SPEED * direction);
	old_dir_x = game->player.dir_x;
	game->player.dir_x = old_dir_x * cos_r - game->player.dir_y * sin_r;
	game->player.dir_y = old_dir_x * sin_r + game->player.dir_y * cos_r;
	old_plane_x = game->player.plane_x;
	game->player.plane_x = old_plane_x * cos_r - game->player.plane_y * sin_r;
	game->player.plane_y = old_plane_x * sin_r + game->player.plane_y * cos_r;
}

void	handle_input(t_game *game)
{
	if (game->keys.w)
		move_player(game, 'W');
	if (game->keys.s)
		move_player(game, 'S');
	if (game->keys.a)
		move_player(game, 'A');
	if (game->keys.d)
		move_player(game, 'D');
	if (game->keys.left)
		rotate_player(game, -1);
	if (game->keys.right)
		rotate_player(game, 1);
}
