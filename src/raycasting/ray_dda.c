/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:20:31 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/05 15:14:07 by Charlye          ###   ########.fr       */
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
//			printf("data->ray.sidedistx = %f\n", data->ray.sidedistx);
		}
		else
		{
			data->ray.sidedisty += data->ray.deltadisty;
			data->ray.mapy += data->ray.stepy;
			data->ray.side = 1;
//			printf("data->ray.sidedisty = %f\n", data->ray.sidedisty);
		}
//		printf("mapx = %d   mapy = %d   grid = %d\n", data->ray.mapx, data->ray.mapy, data->map.grid[data->ray.mapy][data->ray.mapx]);
		if (char_in_string(data->map.grid[data->ray.mapy][data->ray.mapx], "1") == 1)
			data->ray.hit = 1;
	}
	return (true);
}