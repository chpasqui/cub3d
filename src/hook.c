/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:32:01 by sydubois          #+#    #+#             */
/*   Updated: 2025/08/29 11:32:03 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	move_player(t_game *d, int x, int y, char dir)
{
	int	l;
	int	c;

	l = d->map.player_y + y;
	c = d->map.player_x + x;
	if (char_in_string(d->map.grid[l][c], "1"))
	{
		d->map.player_dir = dir;
	}
	else
	{
		d->map.player_x += x;
		d->map.player_y += y;
		d->map.player_dir = dir;
	}
	printf("X = %i Y = %i dir = %c\n", d->map.player_x, d->map.player_y, dir);
	return (true);
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
	printf("touche : %d\n", button);
	if (button == ESC)
		close_window(data);
	else if (button == LEFT || button == KEY_A)
		move_player(data, -1, 0, 'W');
	else if (button == RIGHT || button == KEY_D)
		move_player(data, 1, 0, 'E');
	else if (button == UP || button == KEY_W)
		move_player(data, 0, -1, 'N');
	else if (button == DOWN || button == KEY_S)
		move_player(data, 0, 1, 'S');
	render_loop(data);
	return (0);
}
