/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:53:36 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/09 11:18:06 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "cub3d.h"

static void	init_minimap(t_game *data)
{
	t_minimap *minimap;

	minimap = &data->minimap;
	minimap->color_floor = COLOR_WHITE;
	minimap->color_player = COLOR_GREEN;
	minimap->color_wall = COLOR_BLACK;
	minimap->color_ray = COLOR_RED;
	minimap->square_size = 15;
	minimap->width = 250;
	minimap->height = 150;
	minimap->offset_x = data->mlx.x_window - minimap->width - 20;
	minimap->offset_y = data->mlx.y_window - minimap->height - 20;
	minimap->show = true;
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

static void	init_values_ray(t_ray *ray)
{
	ray->hit = 0;
	ray->side = 0;
	ray->time = 0;
	ray->oldtime = 0;
	ray->frametime = 0.01;
	ray->movespeed = ray->frametime * 5;
	ray->rotspeed = ray->frametime * 3;
	ray->bord = 1.0001;
}

void	init_game(t_game *data)
{
	data->mlx.x_window = 800;
	data->mlx.y_window = 600;
	init_values_player(data);
	init_minimap(data);
	init_values_ray(&data->ray);
}

