/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:40:40 by adnajja           #+#    #+#             */
/*   Updated: 2026/09/01 16:40:43 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_side_dist(t_ray *ray, double px, double py)
{
	if (ray->step_x == 1)
		ray->side_dist_x = (ray->map_x + 1.0 - px) * ray->delta_dist_x;
	else
		ray->side_dist_x = (px - ray->map_x) * ray->delta_dist_x;
	if (ray->step_y == 1)
		ray->side_dist_y = (ray->map_y + 1.0 - py) * ray->delta_dist_y;
	else
		ray->side_dist_y = (py - ray->map_y) * ray->delta_dist_y;
}

void	init_ray(t_ray *ray, t_game *game, int i)
{
	double	px;
	double	py;

	px = game->player.pos_x;
	py = game->player.pos_y;
	ray->camera_x = 2.0 * i / WIDTH - 1;
	ray->ray_dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y + game->player.plane_y * ray->camera_x;
	ray->map_x = (int)px;
	ray->map_y = (int)py;
	if (ray->ray_dir_x < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->ray_dir_y < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
	ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
	init_side_dist(ray, px, py);
}

static void	set_bounds(t_ray *ray)
{
	if (ray->wall_dist < 0.05)
		ray->wall_dist = 0.05;
	ray->line_height = (int)(HEIGHT / ray->wall_dist);
	ray->draw_start = (HEIGHT - ray->line_height) / 2;
	ray->draw_end = (HEIGHT + ray->line_height) / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end > HEIGHT)
		ray->draw_end = HEIGHT;
}

void	dda(t_ray *ray, t_game *game)
{
	while (game->map.grid[ray->map_y][ray->map_x] != '1')
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
	}
	if (ray->side == 0)
		ray->wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->wall_dist = ray->side_dist_y - ray->delta_dist_y;
	set_bounds(ray);
}

void	raycast(t_game *game)
{
	t_ray	ray;
	int		i;

	i = 0;
	while (i < WIDTH)
	{
		init_ray(&ray, game, i);
		dda(&ray, game);
		draw_column(game, &ray, i);
		i++;
	}
}
