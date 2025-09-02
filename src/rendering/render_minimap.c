/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:32:26 by sydubois          #+#    #+#             */
/*   Updated: 2025/09/02 12:33:21 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	print_n_pixel(t_game *data, int x, int y, int color)
{
	int	i;
	int	j;
	int	*pixel;

	pixel = (int *)data->mlx.address;
	j = 0;
	while (j < data->minimap.square_size)
	{
		i = 0;
		while (i < data->minimap.square_size)
		{
			pixel[(y + j) * (data->mlx.line_length / 4) + x + i] = color;
			i++;
		}
		j++;
	}
	return (true);
}

int	get_minimap_color(t_game *data, int m_row, int m_col)
{
	if (!data->map.grid[m_row]
		|| m_col >= (int)ft_strlen(data->map.grid[m_row]))
		return (data->minimap.color_floor);
	else if (data->map.grid[m_row][m_col] == '1')
		return (data->minimap.color_wall);
	else if (m_row == data->map.player_y && m_col == data->map.player_x)
		return (data->minimap.color_player);
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
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window,
		data->mlx.img, 0, 0);
	return (true);
}

