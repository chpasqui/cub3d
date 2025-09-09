/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:52:37 by Charlye           #+#    #+#             */
/*   Updated: 2025/09/09 15:59:42 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_start_dir(t_game *data)
{
	if (data->map.player_dir == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
	}
	else if (data->map.player_dir == 'S')
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
	}
	else if (data->map.player_dir == 'E')
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
	}
	else if (data->map.player_dir == 'W')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
	}
}

static void	player_start_plane(t_game *data)
{
	if (data->map.player_dir == 'N')
	{
		data->player.plane_x = 0.66;
		data->player.plane_y = 0;
	}
	else if (data->map.player_dir == 'S')
	{
		data->player.plane_x = -0.66;
		data->player.plane_y = 0;
	}
	else if (data->map.player_dir == 'E')
	{
		data->player.plane_x = 0;
		data->player.plane_y = 0.66;
	}
	else if (data->map.player_dir == 'W')
	{
		data->player.plane_x = 0;
		data->player.plane_y = -0.66;
	}
}

void	init_values_player(t_game *data)
{
	data->player.pos_x = data->map.player_x + 0.5;
	data->player.pos_y = data->map.player_y + 0.5;
	player_start_dir(data);
	player_start_plane(data);
}
