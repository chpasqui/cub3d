
#include "cub3d.h"

bool	print_pixel(t_game *data, int x, int y, int color)
{
	int	*pixel;

	pixel = (int *)data->mlx.address;
	pixel[y * (data->mlx.line_length / 4) + x] = color;
	return (true);
}

bool	player_start_dir(t_game *data)
{
	if(data->map.player_dir == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
	}
	else if(data->map.player_dir == 'S')
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
	}
	else if(data->map.player_dir == 'E')
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
	}
	else if(data->map.player_dir == 'O')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
	}
	return(true);
}

bool	init_sidedist(t_game *data)
{
	if (data->ray.raydirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.sidedistx = (data->player.pos_x - data->ray.mapx) * data->ray.deltadistx;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.sidedistx = (1 - data->player.pos_x + data->ray.mapx) * data->ray.deltadistx;
	}
	if (data->ray.raydiry < 0)
	{
		data->ray.stepy = -1;
		data->ray.sidedisty = (data->player.pos_y - data->ray.mapy) * data->ray.deltadisty;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.sidedistx = (1 - data->player.pos_y + data->ray.mapy) * data->ray.deltadisty;
	}
	return (true);
}

bool	calc_deltadist(t_game *data, int i)
{
	data->ray.camerax = 2 * i / (double)data->mlx.x_window -1;
	data->ray.raydirx = data->player.dir_x + data->player.plane_x*data->ray.camerax;
	data->ray.raydiry = data->player.dir_y + data->player.plane_y*data->ray.camerax;
	data->ray.mapx = (int)data->player.pos_x;
	data->map.player_x = data->ray.mapx;//SDU remplacer mapx  minimap
	data->ray.mapy = (int)data->player.pos_y;
	data->map.player_y = data->ray.mapy;//SDU remplacer mapx  minimap
	data->ray.deltadistx = sqrt(1 + ((data->ray.raydiry * data->ray.raydiry) / (data->ray.raydirx * data->ray.raydirx)));
	data->ray.deltadisty = sqrt(1 + ((data->ray.raydirx * data->ray.raydirx) / (data->ray.raydiry * data->ray.raydiry)));
	return(true);
}

bool	algo_dda(t_game *data)
{
	while(!data->ray.hit)
	{
		if(data->ray.sidedistx < data->ray.sidedisty)
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
//			printf("mapx = %d   mapy = %d   grid = %d\n", data->ray.mapx, data->ray.mapy, data->map.grid[data->ray.mapy][data->ray.mapx]);
		if(char_in_string(data->map.grid[data->ray.mapy][data->ray.mapx], "1") == 1)
			data->ray.hit = 1;
	}
	return(true);
}

bool	calc_lineheight(t_game *data)
{
	if(data->ray.side == 0)
		data->ray.perpwalldist = data->ray.sidedistx - data->ray.deltadistx;
	else
		data->ray.perpwalldist = data->ray.sidedisty - data->ray.deltadisty;
	data->ray.lineHeight = (int)(data->mlx.y_window / data->ray.perpwalldist);
	return(true);
}

bool	calc_draw_se(t_game *data)
{
	data->ray.drawstart = data->mlx.y_window / 2 - data->ray.lineHeight / 2;
	if(data->ray.drawstart < 0)
		data->ray.drawstart = 0;
	data->ray.drawend = data->mlx.y_window / 2 + data->ray.lineHeight / 2;
	if(data->ray.drawend >= data->mlx.y_window)
		data->ray.drawend = data->mlx.y_window - 1;
	return(true);
}

bool	print_ray_v0(t_game *data, int i)
{
	int	color;
	int	j;

//fonce pour les murs verticaux
	color = COLOR_BLUE;
	if(data->ray.side == 0)
	color = 0x00000080;

//reset en noir
	j = 0;
	while( j < data->mlx.y_window)
	{
		print_pixel(data, i, j, COLOR_BLACK);
		j++;
	}
//murs en bleu
	j = data->ray.drawstart;
	while( j < data->ray.drawend)
	{
//		printf("i = %i  j= %i\n", i, j);
		print_pixel(data, i, j, color);
		j++;
	}
	return(true);
}

bool	render_ray(t_game *data)
{
	int	i;


//	printf("pos_x = %f   pos_y = %f\n", data->player.pos_x, data->player.pos_y);
	player_start_dir(data);
	i = 0;
	while(i <= data->mlx.x_window)
	{
		data->ray.hit = 0;
//		printf("\ni = %d\n", i);
		calc_deltadist(data, i);
//		printf("camerax = %f   deltadistx = %f  deltadisty = %f\n", data->ray.camerax, data->ray.deltadistx, data->ray.deltadisty);
//		usleep(10000);
		init_sidedist(data);
		algo_dda(data);
		calc_lineheight(data);
//		printf("perpwalldist = %f  lineHeight = %i  \n", data->ray.perpwalldist, data->ray.lineHeight);
		calc_draw_se(data);
//		printf("drawstart = %i  drawend= %i\n", data->ray.drawstart, data->ray.drawend);
		print_ray_v0(data, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window, data->mlx.img, 0, 0);
	return(true);
}
