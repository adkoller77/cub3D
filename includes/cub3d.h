/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:40:40 by adnajja           #+#    #+#             */
/*   Updated: 2026/09/01 16:40:43 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"

# define WIDTH 1280
# define HEIGHT 720

typedef struct s_ray
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
}	t_ray;

typedef struct s_player
{
	int		player_x;
	int		player_y;
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		size;
	int		floor_color[3];
	int		ceil_color[3];
	char	*texture_path[4];
}	t_map;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_texture	tex[4];
}	t_mlx;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	t_mlx		mlx;
	t_keys		keys;
}	t_game;

int		print_error(char *msg);
void	free_map(char **map, int size);
void	free_game(t_game *game);
int		load_textures(t_game *game);
void	free_textures(t_game *game);
void	draw_column(t_game *game, t_ray *ray, int x);
void	raycast(t_game *game);
void	dda(t_ray *ray, t_game *game);
void	init_ray(t_ray *ray, t_game *game, int i);
void	init_game(t_game *game);
int		init_mlx(t_game *game);
void	free_mlx(t_game *game);
int		render(t_game *game);
int		close_window(t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void	handle_input(t_game *game);
void	move_player(t_game *game, char dir);
void	rotate_player(t_game *game, int direction);
void	dir_player(t_game *game);
int		pos_player(t_game *game, int i, int j, char c);
int		check_chars_map(t_game *game);
int		check_elements(t_game *game);
int		is_blank_line(char *line);
void	put_pixel(t_game *game, int x, int y, int color);
int		parse_element(char *line, t_game *game);
int		parse_map(int fd, t_game *game, char *line);
int		parse_rgb(char *line, int *color);
int		parse_color(char *line, t_game *game, int is_floor);
int		parse_texture(char *line, t_game *game, int index);
int		read_cub(int fd, t_game *game);
void	flush_gnl(int fd);
int		validate_map(t_game *game);
char	**copy_map(t_game *game);
int		flood_fill(char **map, int i, int j, int size);

#endif
