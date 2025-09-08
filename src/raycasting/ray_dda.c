/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:20:31 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/08 11:52:51 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	algo_dda(t_game *data)
{
	while (!data->ray.hit)
	{
		if (data->ray.sidedistx < data->ray.sidedisty)
		{
			data->ray.sidedistx += data->ray.deltadistx;
			data->ray.mapx += data->ray.stepx;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sidedisty += data->ray.deltadisty;
			data->ray.mapy += data->ray.stepy;
			data->ray.side = 1;
		}
		if (c_in_s(data->map.grid[data->ray.mapy][data->ray.mapx], "1") == 1)
			data->ray.hit = 1;
	}
	return (true);
}
/*
printf("mapx = %d   mapy = %d   grid = %d\n", data->ray.mapx,
data->ray.mapy, data->map.grid[data->ray.mapy][data->ray.mapx]);
*/
