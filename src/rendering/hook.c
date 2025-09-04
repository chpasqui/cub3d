/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:32:01 by sydubois          #+#    #+#             */
/*   Updated: 2025/09/04 21:17:36 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	key_hook(t_game *data)
{
	if (data->key.up || data->key.w)
		move_map_up(data);
	if (data->key.down || data->key.s)
		move_map_down(data);
	if (data->key.a)
		move_map_left(data);
	if (data->key.d)
		move_map_right(data);
	if (data->key.right)
		rotate(data, 1);
	if (data->key.left)
		rotate(data, -1);
	render_loop(data);
	return (0);
}
