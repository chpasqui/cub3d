/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:53:36 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/05 14:58:12 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *data)
{
	ft_bzero(data, sizeof(t_game));
}

void	init_minimap(t_minimap *minimap)
{
	minimap->color_floor = COLOR_WHITE;
	minimap->color_player = COLOR_GREEN;
	minimap->color_wall = COLOR_RED;
	minimap->color_ray = COLOR_RED;
	minimap->square_size = 15;
	minimap->width = 250;
	minimap->height = 150;
	minimap->offset_x = 20;
	minimap->offset_y = 20;
	minimap->show = true;
}

void	init_map(t_map *map)
{
	ft_bzero(map, sizeof(t_map));
	map->floor.r = -1;
	map->floor.g = -1;
	map->floor.b = -1;
	map->ceiling.r = -1;
	map->ceiling.g = -1;
	map->ceiling.b = -1;
}

void	init_key(t_key k)
{
	k.w = 0;
	k.s = 0;
	k.a = 0;
	k.d = 0;
	k.up = 0;
	k.down = 0;
	k.left = 0;
	k.right = 0;
}

bool	init_value(t_game *data)
{
	data->mlx.x_window = 800;
	data->mlx.y_window = 600;
	init_minimap(&data->minimap);
	data->player.pos_x = data->map.player_x + 0.5;
	data->player.pos_y = data->map.player_y + 0.5;
	player_start_dir(data);
	data->player.plane_x = 0.66;
	data->player.plane_y = 0;
	data->ray.hit = 0;
	data->ray.side = 0;
	data->ray.time = 0;
	data->ray.oldtime = 0;
	data->ray.frametime = 0.01;
	data->ray.movespeed = data->ray.frametime * 5;
	data->ray.rotspeed = data->ray.frametime * 3;
	init_key(data->key);
	data->ray.bord = 1.0001;
	return (true);
}

bool	init_mlx(t_game *data)
{
	data->mlx.mlx = mlx_init();
	if (data->mlx.mlx == NULL)
		handle_error(data, MLX_ERROR);
	data->mlx.window = mlx_new_window(data->mlx.mlx, data->mlx.x_window,
			data->mlx.y_window, "cub3D");
	data->mlx.img = mlx_new_image(data->mlx.mlx, data->mlx.x_window,
			data->mlx.y_window);
	data->mlx.address = mlx_get_data_addr(data->mlx.img,
			&data->mlx.bits_per_pixel, &data->mlx.line_length,
			&data->mlx.endian);
	return (true);
}

bool	player_start_dir(t_game *data)
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
	else if (data->map.player_dir == 'O')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
	}
	return (true);
}
