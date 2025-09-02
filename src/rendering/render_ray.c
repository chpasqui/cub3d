
#include "cub3d.h"

bool render_ray(t_game *data)
{
	printf("render");
	data->player.pos_x = 100;
	data->player.pos_y = 100;
	data->player.dir_x = 0;
	data->player.dir_y = -1;
	data->player.plane_x = 0.66;
	data->player.plane_y = 0;
	data->ray.hit = 0;
	data->ray.side = 0;

	int	i;

	i = 0;
	while(i <= data->mlx.x_window)
	{
		data->ray.camerax = 2 * i / data->mlx.x_window -1;
		data->ray.raydirx = data->player.dir_x + data->player.plane_x*data->ray.camerax;
		data->ray.raydiry = data->player.dir_y + data->player.plane_y*data->ray.camerax;
		data->ray.mapx = data->player.pos_x;
		data->ray.mapy = data->player.pos_y;
		data->ray.deltadistx = sqrt(1 + ((data->ray.raydiry * data->ray.raydiry) / (data->ray.raydirx * data->ray.raydirx)));
		data->ray.deltadisty = sqrt(1 + ((data->ray.raydirx * data->ray.raydirx) / (data->ray.raydiry * data->ray.raydiry)));

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

		while(!data->ray.hit)
		{
			if(data->ray.sidedistx < data->ray.sidedisty)
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
			if(data->map.grid[data->ray.mapy][data->ray.mapx] > 0)
				data->ray.hit = 1;
		}



		i++;


	}


}
