/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:57:36 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/09 14:10:05 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_in_image(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->address + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(int *)dst = color;
}

bool	print_n_pixel(t_game *data, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->minimap.square_size)
	{
		i = 0;
		while (i < data->minimap.square_size)
		{
			put_pixel_in_image(&data->mlx, x + i, y + j, color);
			i++;
		}
		j++;
	}
	return (true);
}
