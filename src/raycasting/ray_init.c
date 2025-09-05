/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:12:46 by Charlye           #+#    #+#             */
/*   Updated: 2025/09/05 16:26:48 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	calc_perpwalldist(t_game *data)
{
	if (data->ray.side == 0)
		data->ray.perpwalldist = data->ray.sidedistx - data->ray.deltadistx;
	else
		data->ray.perpwalldist = data->ray.sidedisty - data->ray.deltadisty;
	return (true);
}

bool	init_sidedist(t_game *data)
{
	t_ray	*r;

	r = &data->ray;
	if (r->raydirx < 0)
		r->sidedistx = (data->player.pos_x - r->mapx) * r->deltadistx;
	else
		r->sidedistx = (1 - data->player.pos_x + r->mapx) * r->deltadistx;
	if (r->raydiry < 0)
		r->sidedisty = (data->player.pos_y - r->mapy) * r->deltadisty;
	else
		r->sidedisty = (1 - data->player.pos_y + r->mapy) * r->deltadisty;
	return (true);
}

bool	init_step(t_game *data)
{
	if (data->ray.raydirx < 0)
		data->ray.stepx = -1;
	else
		data->ray.stepx = 1;
	if (data->ray.raydiry < 0)
		data->ray.stepy = -1;
	else
		data->ray.stepy = 1;
	return (true);
}

bool	calc_deltadist(t_game *data, int i)
{
	t_ray	*r;


	r = &data->ray;
	r->camerax = 2 * i / (double)data->mlx.x_window -1;
	r->raydirx = data->player.dir_x + data->player.plane_x * r->camerax;
	r->raydiry = data->player.dir_y + data->player.plane_y * r->camerax;
	r->mapx = (int)data->player.pos_x;
	data->map.player_x = r->mapx;//SDU remplacer mapx  minimap
	r->mapy = (int)data->player.pos_y;
	data->map.player_y = r->mapy;//SDU remplacer mapx  minimap)
//	r->deltadistx = sqrt(1 + ((r->raydiry * r->raydiry) / (r->raydirx * r->raydirx)));
//	r->deltadisty = sqrt(1 + ((r->raydirx * r->raydirx) / (r->raydiry * r->raydiry)));
	if(r->raydirx == 0)
		r->deltadistx = 1e30;
	else
		r->deltadistx = fabs(1/r->raydirx);

	if(r->raydiry == 0)
		r->deltadisty = 1e30;
	else
		r->deltadisty = fabs(1/r->raydiry);

	return (true);
}

void	init_ray(t_game *data, int x)
{
	data->ray.hit = 0;
	//		printf("\ni = %d\n", i);
	calc_deltadist(data, x);
	init_sidedist(data);
	//	printf("camerax = %f   deltadistx = %f  deltadisty = %f\n", data->ray.camerax, data->ray.deltadistx, data->ray.deltadisty);
	//	usleep(10000);
	init_step(data);
	calc_perpwalldist(data);
}