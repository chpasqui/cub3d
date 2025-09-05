/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ceiling_floor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:50:39 by Charlye           #+#    #+#             */
/*   Updated: 2025/09/05 16:18:43 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_ceiling(t_game *data, int x, int y)
{
	int	color;

	color = (data->map.ceiling.r << 16) | (data->map.ceiling.g << 8)
		| data->map.ceiling.b;
	while (y < data->render.draw_start)
	{
		put_pixel_in_image(&data->mlx, x, y, color);
		y++;
	}
}

void	render_floor(t_game *data, int x, int y)
{
	int	color;

	color = (data->map.floor.r << 16) | (data->map.floor.g << 8)
		| data->map.floor.b;
	while (y < data->mlx.y_window)
	{
		put_pixel_in_image(&data->mlx, x, y, color);
		y++;
	}
}
