/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:32:01 by sydubois          #+#    #+#             */
/*   Updated: 2025/09/04 17:20:10 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	move_minimap(t_game *d, int x, int y, char dir)
{
	int	l;
	int	c;

	l = d->map.player_y + y;
	c = d->map.player_x + x;
	if (char_in_string(d->map.grid[l][c], "1"))
	{
//		d->map.player_dir = dir;
		printf("P1\n");
		(void)dir;
	}
	else
	{
		d->map.player_x += x;
		d->map.player_y += y;
//		d->map.player_dir = dir;
		printf("P1\n");
	}
	printf("X = %i Y = %i dir = %c\n", d->map.player_x, d->map.player_y, dir);
	return (true);
}

bool move_map_up(t_game *data)
{
	int	l;
	int	c;

	l = (int)(data->player.pos_x + data->player.dir_x * data->ray.movespeed * data->ray.bord);
	c = (int)data->player.pos_y;
	if (!char_in_string(data->map.grid[c][l], "1"))
		data->player.pos_x += data->player.dir_x * data->ray.movespeed;
	l = (int)data->player.pos_x;
	c = (int)(data->player.pos_y + data->player.dir_y * data->ray.movespeed * data->ray.bord);
	if (!char_in_string(data->map.grid[c][l], "1"))
		data->player.pos_y += data->player.dir_y * data->ray.movespeed;
	return(true);
}

bool move_map_down(t_game *data)
{
	int	l;
	int	c;

	l = (int)(data->player.pos_x - data->player.dir_x * data->ray.movespeed * data->ray.bord);
	c = (int)data->player.pos_y;
	if (!char_in_string(data->map.grid[c][l], "1"))
		data->player.pos_x -= data->player.dir_x * data->ray.movespeed;
	l = (int)data->player.pos_x;
	c = (int)(data->player.pos_y - data->player.dir_y * data->ray.movespeed * data->ray.bord);
	if (!char_in_string(data->map.grid[c][l], "1"))
		data->player.pos_y -= data->player.dir_y * data->ray.movespeed;
	return(true);
}

bool move_map_left(t_game *data)
{
	int	l;
	int	c;

	l = (int)(data->player.pos_x + data->player.dir_y * data->ray.movespeed * data->ray.bord);
	c = (int)data->player.pos_y;

	if (!char_in_string(data->map.grid[c][l], "1"))
		data->player.pos_x += data->player.dir_y * data->ray.movespeed;

	l = (int)data->player.pos_x;
	c = (int)(data->player.pos_y - data->player.dir_x * data->ray.movespeed * data->ray.bord);
	if (!char_in_string(data->map.grid[c][l], "1"))
		data->player.pos_y -= data->player.dir_x * data->ray.movespeed;

	return(true);
}

bool move_map_right(t_game *data)
{
	int	l;
	int	c;

	l = (int)(data->player.pos_x - data->player.dir_y * data->ray.movespeed * data->ray.bord);
	c = (int)data->player.pos_y;

	if (!char_in_string(data->map.grid[c][l], "1"))
		data->player.pos_x -= data->player.dir_y * data->ray.movespeed;

	l = (int)data->player.pos_x;
	c = (int)(data->player.pos_y + data->player.dir_x * data->ray.movespeed * data->ray.bord);
	if (!char_in_string(data->map.grid[c][l], "1"))
		data->player.pos_y += data->player.dir_x * data->ray.movespeed;

	return(true);
}

int	mouse_hook(int button, int x, int y, t_game *data)
{
	printf("touche : %d  x = %d  y = %d\n", button, x, y);
	if (button == SCROLL_UP || button == CLICK_L)
	{
		printf("click L px = %d\n", data->map.player_x);
	}
	else if (button == SCROLL_DOWN || button == CLICK_R)
	{
		printf("click R py = %d\n", data->map.player_y);
	}
	render_loop(data);
	return (0);
}

int	key_hook(int button, t_game *data)
{
	data->ray.movespeed = 1; //SDU
	printf("touche : %d\n", button);
	if (button == ESC)
		close_window(data);
	else if (button == KEY_A)
	{
		move_minimap(data, -1, 0, 'W');
	}
	else if (button == KEY_D)
		move_minimap(data, 1, 0, 'E');
	else if (button == UP || button == KEY_W)
	{
		move_map_up(data);
		//move_minimap(data, 0, -1, 'N');
		//printf("pos_x = %f  pos_y = %f\n", data->player.pos_x, data->player.pos_y);
	}
	else if (button == DOWN || button == KEY_S)
	{
		//move_map_down(data);
		printf("down\n");
		move_minimap(data, 0, 1, 'S');
	}
	else if (button == LEFT)
		move_minimap(data, -1, 0, 'W');
	else if (button == RIGHT)
		move_minimap(data, 1, 0, 'E');
	render_loop(data);
	return (0);
}


int	key_hook2(t_game *data)
{

	if (data->key.up || data->key.w)
		move_map_up(data);
	if (data->key.down || data->key.s)
		move_map_down(data);
	if (data->key.a)
		move_map_left(data);
	if (data->key.d)
		move_map_right(data);


	render_loop(data);
	return (0);
}


bool move_map_up_V0(t_game *data)
{
	int	l;
	int	c;

	printf("move_map_up\n");

	l = (int)(data->player.pos_x + data->player.dir_x * data->ray.movespeed);
	c = (int)data->player.pos_y;
//	printf("lx = %i  cx = %i grid = %i\n", l, c, char_in_string(data->map.grid[l][c], "1"));
	if (char_in_string(data->map.grid[l][c], "1") != 1)
	{
	//	printf("movespeedx = %f   dir_x = %f\n", data->ray.movespeed, data->player.dir_x);
		data->player.pos_x += data->player.dir_x * data->ray.movespeed;
	//	printf("movespeedx = %f   dir_x = %f\n", data->ray.movespeed, data->player.dir_x);
	}

	l = (int)data->player.pos_x;
	c = (int)(data->player.pos_y + data->player.dir_y * data->ray.movespeed);
//	printf("ly = %i  cy = %i  grid = %i\n", l, c, char_in_string(data->map.grid[l][c], "1"));
	if (char_in_string(data->map.grid[l][c], "1") != 1)
	{
//		printf("movespeedy = %f   dir_y = %f pos_y = %f\n", data->ray.movespeed, data->player.dir_y, data->player.pos_y);
		data->player.pos_y += data->player.dir_y * data->ray.movespeed;
//		printf("movespeedy = %f   dir_y = %f pos_y = %f\n", data->ray.movespeed, data->player.dir_y, data->player.pos_y);
	}
	return(true);
}
