/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:15:44 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/09 14:05:04 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_str_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_map(t_map	*map)
{
	if (map->lines)
		free_str_array(map->lines);
	if (map->grid)
		free_str_array(map->grid);
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->ea_path)
		free(map->ea_path);
	if (map->we_path)
		free(map->we_path);
}

void	free_texture(t_game *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->tex[i].img)
			mlx_destroy_image(data->mlx.mlx, data->tex[i].img);
		i++;
	}
}

void	free_mlx(t_mlx	*mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->window)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
}

void	free_game(t_game *data)
{
	free_map(&data->map);
	free_texture(data);
	free_mlx(&data->mlx);
}
