/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:40:40 by adnajja           #+#    #+#             */
/*   Updated: 2026/09/01 16:40:43 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	rgb_to_int(int *rgb)
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

static int	get_tex_color(t_texture *tex, int x, int y)
{
	char	*px;

	px = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)px);
}

static t_texture	*pick_texture(t_game *game, t_ray *ray)
{
	t_texture	*tex;
	double		wall_x;

	if (ray->side == 0 && ray->step_x > 0)
		tex = &game->mlx.tex[3];
	else if (ray->side == 0)
		tex = &game->mlx.tex[2];
	else if (ray->step_y > 0)
		tex = &game->mlx.tex[0];
	else
		tex = &game->mlx.tex[1];
	if (ray->side == 0)
		wall_x = game->player.pos_y + ray->wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.pos_x + ray->wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * tex->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_x = tex->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->tex_x = tex->width - ray->tex_x - 1;
	if (ray->tex_x < 0)
		ray->tex_x = 0;
	if (ray->tex_x >= tex->width)
		ray->tex_x = tex->width - 1;
	return (tex);
}

static void	draw_wall(t_game *game, t_ray *ray, t_texture *tex, int x)
{
	int	raw_start;
	int	y;
	int	tex_y;

	raw_start = (HEIGHT - ray->line_height) / 2;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (y - raw_start) * tex->height / ray->line_height;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		put_pixel(game, x, y, get_tex_color(tex, ray->tex_x, tex_y));
		y++;
	}
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	t_texture	*tex;
	int			ceil_color;
	int			floor_color;
	int			y;

	tex = pick_texture(game, ray);
	draw_wall(game, ray, tex, x);
	ceil_color = rgb_to_int(game->map.ceil_color);
	floor_color = rgb_to_int(game->map.floor_color);
	y = 0;
	while (y < ray->draw_start)
		put_pixel(game, x, y++, ceil_color);
	y = ray->draw_end;
	while (y < HEIGHT)
		put_pixel(game, x, y++, floor_color);
}
