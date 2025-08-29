/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:53:36 by chpasqui          #+#    #+#             */
/*   Updated: 2025/08/29 12:05:35 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *data)
{
	ft_bzero(&data, sizeof(t_game));
}

bool	init_value(t_game *data)
{
	data->mlx.x_window = 800;
	data->mlx.y_window = 600;
	data->map.square_size = 10;
	data->map.x = 0;
	data->map.y = 0;
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
