
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

	int	i;

	i = 0;
	while(i <= 800)
	{
		data->ray.camerax = 2 * i / 800 -1;
		data->ray.raydirx = data->player.dir_x + data->player.plane_x*data->ray.camerax;
		data->ray.raydiry = data->player.dir_y + data->player.plane_y*data->ray.camerax;


		
		i++;


	}

	
}