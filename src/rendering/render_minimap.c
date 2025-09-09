/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:32:26 by sydubois          #+#    #+#             */
/*   Updated: 2025/09/09 12:08:55 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_minimap_color(t_game *data, int m_row, int m_col)
{
	if (!data->map.grid[m_row]
		|| m_col >= (int)ft_strlen(data->map.grid[m_row]))
		return (data->minimap.color_floor);
	else if (data->map.grid[m_row][m_col] == '1')
		return (data->minimap.color_wall);
	else
		return (data->minimap.color_floor);
}

void	render_minimap_case(t_game *data, t_minimap *minimap, int row, int col)
{
	int	m_row;
	int	m_col;
	int	view_rows;
	int	view_cols;
	int	color;

	view_rows = minimap->height / minimap->square_size;
	view_cols = minimap->width / minimap->square_size;
	m_row = data->map.player_y - view_rows / 2 + row;
	m_col = data->map.player_x - view_cols / 2 + col;
	if (m_row < 0 || m_row >= data->map.height || m_col < 0
		|| m_col >= data->map.width)
		color = COLOR_BLACK;
	else
		color = get_minimap_color(data, m_row, m_col);
	print_n_pixel(data, minimap->offset_x + col * minimap->square_size,
		minimap->offset_y + row * minimap->square_size, color);
}

void	draw_circle(t_game *data, int px, int py)
{
	int	radius;
	int	x;
	int	y;

	radius = data->minimap.square_size / 2;
	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				put_pixel_in_image(&data->mlx, px + x, py + y,
					data->minimap.color_player);
			x++;
		}
		y++;
	}

}

void	draw_direction(t_game *data, int px, int py)
{
	int	radius;
	int	i;
	int	x;
	int	y;

	radius = data->minimap.square_size;
	i = 0;

	while (i < radius)
	{
		x = px + (int)(data->player.dir_x * i);
		y = py + (int)(data->player.dir_y * i);
		put_pixel_in_image(&data->mlx, x, y, data->minimap.color_ray);
		i++;
	}
}

bool	render_minimap(t_game *data)
{
	int	view_rows;
	int	view_cols;
	int	row;
	int	col;

	view_rows = data->minimap.height / data->minimap.square_size;
	view_cols = data->minimap.width / data->minimap.square_size;
	row = 0;
	while (row < view_rows)
	{
		col = 0;
		while (col < view_cols)
		{
			render_minimap_case(data, &data->minimap, row, col);
			col++;
		}
		row++;
	}
	draw_circle(data, data->minimap.offset_x + data->minimap.width / 2,
		data->minimap.offset_y + data->minimap.height / 2);
	draw_direction(data, data->minimap.offset_x + data->minimap.width / 2,
		data->minimap.offset_y + data->minimap.height / 2);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window,
		data->mlx.img, 0, 0);
	return (true);
}
