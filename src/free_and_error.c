/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:15:44 by chpasqui          #+#    #+#             */
/*   Updated: 2025/08/18 19:46:22 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map	*map)
{
	int	i;

	i = 0;
	if (map->grid)
	{
		while (map->grid[i])
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->ea_path)
		free(map->ea_path);
	if (map->we_path)
		free(map->we_path);
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
	free_mlx(&data->mlx);
}

int	clean_exit(t_game *data, int code)
{
	free_game(data);
	exit(code);
}

void	handle_error(t_game *data, char *msg)
{
	printf("Error\n%s\n", msg);
	clean_exit(data, EXIT_FAILURE);
}
