/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:32:01 by sydubois          #+#    #+#             */
/*   Updated: 2025/09/09 16:05:11 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (data->key.esc)
		close_window(data);
	render_game(data);
	return (0);
}

int	key_hook2(t_game *data)
{
	if (data->key.up || data->key.w)
		move_map_up2(data);
	if (data->key.down || data->key.s)
		move_map_down2(data);
	if (data->key.a)
		move_map_left2(data);
	if (data->key.d)
		move_map_right2(data);
	if (data->key.right)
		rotate(data, 1);
	if (data->key.left)
		rotate(data, -1);
	if (data->key.esc)
		close_window(data);
	render_game(data);
	return (0);
}
