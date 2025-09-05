/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:36:46 by sydubois          #+#    #+#             */
/*   Updated: 2025/09/05 09:22:36 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	print_pixel(t_game *data, int x, int y, int color)
{
	int	*pixel;

	pixel = (int *)data->mlx.address;
	pixel[y * (data->mlx.line_length / 4) + x] = color;
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

bool	calc_lineheight(t_game *data)
{
	if (data->ray.side == 0)
		data->ray.perpwalldist = data->ray.sidedistx - data->ray.deltadistx;
	else
		data->ray.perpwalldist = data->ray.sidedisty - data->ray.deltadisty;
	data->ray.lineHeight = (int)(data->mlx.y_window / data->ray.perpwalldist);
	return (true);
}

bool	calc_draw_se(t_game *data)
{
	data->ray.drawstart = data->mlx.y_window / 2 - data->ray.lineHeight / 2;
	if (data->ray.drawstart < 0)
		data->ray.drawstart = 0;
	data->ray.drawend = data->mlx.y_window / 2 + data->ray.lineHeight / 2;
	if (data->ray.drawend >= data->mlx.y_window)
		data->ray.drawend = data->mlx.y_window - 1;
	return (true);
}

bool	print_ray_v0(t_game *data, int i)
{
	int	color;
	int	j;

//fonce pour les murs verticaux
	color = COLOR_BLUE;
	if (data->ray.side == 0)
		color = 0x00000080;
//reset en noir
	j = 0;
	while (j < data->mlx.y_window)
	{
		print_pixel(data, i, j, COLOR_BLACK);
		j++;
	}
//murs en bleu
	j = data->ray.drawstart;
	while (j < data->ray.drawend)
	{
//		printf("i = %i  j= %i\n", i, j);
		print_pixel(data, i, j, color);
		j++;
	}
	return (true);
}

bool	render_ray(t_game *data)
{
	int	i;

	printf("px=%.2f  py=%.2f  dix=%.2f  diy=%.2f  plx=%.2f  ply=%.2f  dex=%2.f  dey=%2.f  six=%2.f  siy=%2.f\n", data->player.pos_x, data->player.pos_y, data->player.dir_x, data->player.dir_y, data->player.plane_x, data->player.plane_y
	,data->ray.deltadistx, data->ray.deltadisty, data->ray.sidedistx, data->ray.sidedisty);
	i = 0;
	while (i <= data->mlx.x_window)
	{
		data->ray.hit = 0;
//		printf("\ni = %d\n", i);
		calc_deltadist(data, i);
//		printf("camerax = %f   deltadistx = %f  deltadisty = %f\n", data->ray.camerax, data->ray.deltadistx, data->ray.deltadisty);
//		usleep(10000);
		init_sidedist(data);
		init_step(data);
		algo_dda(data);
		calc_lineheight(data);
//		printf("perpwalldist = %f  lineHeight = %i  \n", data->ray.perpwalldist, data->ray.lineHeight);
		calc_draw_se(data);
//		printf("drawstart = %i  drawend= %i\n", data->ray.drawstart, data->ray.drawend);
		print_ray_v0(data, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window, data->mlx.img, 0, 0);
	return (true);
}
