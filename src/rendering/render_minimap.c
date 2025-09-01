/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:32:26 by sydubois          #+#    #+#             */
/*   Updated: 2025/09/01 09:26:59 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	print_n_pixel(t_game *data, int *pixel, int color)
{
	int	i;

	i = 0;
	while (i < data->minimap.square_size)
	{
		pixel[(data->minimap.y) * (data->mlx.line_length / 4)
			+ data->minimap.x] = color;
		i++;
		data->minimap.x++;
	}
	return (true);
}

bool	render_logo(t_game *data)
{
	char	*img_logo;
	int		width;
	int		height;
	void	*logo;

	img_logo = "./src/cub3d_logo_30x30.xpm";
	width = 30;
	height = 30;
	if (access(img_logo, F_OK) != 0)
	{
		perror("fichire introuvable\n");
		return (false);
	}
	logo = mlx_xpm_file_to_image(data->mlx.mlx, img_logo, &width, &height);
	if (!logo)
	{
		printf("probleme logo %s et l = %p\n ", img_logo, logo);
		return (false);
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window, logo, 100, 0);
	return (true);
}


bool	render_minimap(t_game *data)
{
	int		c;
	int		l;
	int		*pixel = (int *)data->mlx.address;
	char	**grid = data->map.grid;

	l = 0;
	while (l < data->map.height)
	{
		data->minimap.y = l * data->minimap.square_size;
		while (data->minimap.y <= data->minimap.square_size * (l + 1))
		{
			c = 0;
			data->minimap.x = 0;
			while (c < data->map.width)
			{
//				printf("x = %i   y = %i   c = %i   l = %i   grid = %c\n", data->map.x, data->map.y, c , l, grid[l][c]);
				if (grid[l][c] && char_in_string(grid[l][c], "1"))
					print_n_pixel(data, pixel, COLOR_RED);
				else if (l == data->map.player_y && c == data->map.player_x)
					print_n_pixel(data, pixel, COLOR_GREEN);
				else
					print_n_pixel(data, pixel, COLOR_WHITE);
				c++;
			}
			data->minimap.y++;
		}
		l++;
	}
//	pixel[50 * (data->mlx.line_length/4) + 100] = rouge;
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window, data->mlx.img, 0, 0);
	return (true);
}

bool	render_loop(t_game *data)
{
	render_minimap(data);
	render_logo(data);
	return (true);
}
