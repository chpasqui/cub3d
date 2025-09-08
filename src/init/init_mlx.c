/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:53:36 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/08 18:57:07 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "cub3d.h"

bool	init_mlx(t_game *data)
{
	data->mlx.mlx = mlx_init();
	if (data->mlx.mlx == NULL)
		return (false);
	data->mlx.window = mlx_new_window(data->mlx.mlx, data->mlx.x_window,
			data->mlx.y_window, "cub3D");
	data->mlx.img = mlx_new_image(data->mlx.mlx, data->mlx.x_window,
			data->mlx.y_window);
	data->mlx.address = mlx_get_data_addr(data->mlx.img,
			&data->mlx.bits_per_pixel, &data->mlx.line_length,
			&data->mlx.endian);
	return (true);
}
