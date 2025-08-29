/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/08/29 14:19:45 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *data)
{
	ft_bzero(&data, sizeof(t_game));

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

bool	init_value(t_game *data)
{
	data->mlx.x_window = 800;
	data->mlx.y_window = 600;
	return (true);
}

bool	init_mlx(t_game *data)
{
	data->mlx.mlx = mlx_init();
	if (data->mlx.mlx == NULL)
		handle_error(data, MLX_ERROR);
	data->mlx.window = mlx_new_window(data->mlx.mlx, data->mlx.x_window, data->mlx.y_window, "cub3D");
	data->mlx.img = mlx_new_image(data->mlx.mlx, data->mlx.x_window, data->mlx.y_window);
	data->mlx.address = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel, &data->mlx.line_length, &data->mlx.endian);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window, data->mlx.img, 0, 0);
	return (true);
}
