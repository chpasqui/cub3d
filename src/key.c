#include "cub3d.h"

int	key_press(int keycode, t_game *data)
{
	if (keycode == KEY_W)
		data->key.w = 1;
	if (keycode == KEY_S)
		data->key.s = 1;
	if (keycode == KEY_A)
		data->key.a = 1;
	if (keycode == KEY_D)
		data->key.d = 1;
	if (keycode == UP)
		data->key.up = 1;
	if (keycode == DOWN)
		data->key.down = 1;
	if (keycode == LEFT)
		data->key.left = 1;
	if (keycode == RIGHT)
		data->key.right = 1;
	return (true);
}



int	key_release(int keycode, t_game *data)
{
	if (keycode == KEY_W)
		data->key.w = 0;
	if (keycode == KEY_S)
		data->key.s = 0;
	if (keycode == KEY_A)
		data->key.a = 0;
	if (keycode == KEY_D)
		data->key.d = 0;
	if (keycode == UP)
		data->key.up = 0;
	if (keycode == DOWN)
		data->key.down = 0;
	if (keycode == LEFT)
		data->key.left = 0;
	if (keycode == RIGHT)
		data->key.right = 0;
	return (true);

}
