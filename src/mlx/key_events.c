#include "cub3d.h"
#include <X11/keysym.h>

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_window(game);
	if (keycode == XK_w)
		game->keys.w = 1;
	if (keycode == XK_s)
		game->keys.s = 1;
	if (keycode == XK_a)
		game->keys.a = 1;
	if (keycode == XK_d)
		game->keys.d = 1;
	if (keycode == XK_Left)
		game->keys.left = 1;
	if (keycode == XK_Right)
		game->keys.right = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->keys.w = 0;
	if (keycode == XK_s)
		game->keys.s = 0;
	if (keycode == XK_a)
		game->keys.a = 0;
	if (keycode == XK_d)
		game->keys.d = 0;
	if (keycode == XK_Left)
		game->keys.left = 0;
	if (keycode == XK_Right)
		game->keys.right = 0;
	return (0);
}
