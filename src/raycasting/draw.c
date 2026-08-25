/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 23:40:07 by adnajja           #+#    #+#             */
/*   Updated: 2026/08/19 20:54:38 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->mlx.addr + (y * game->mlx.line_len
			+ x * (game->mlx.bpp / 8));
	*(unsigned int *)dst = color;
}
