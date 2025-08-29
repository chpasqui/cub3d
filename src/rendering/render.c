#include "cub3d.h"

bool	render_logo(t_game *data)
{
	char	*img_logo;
	int		width;
	int		height;
	void	*logo;

	img_logo = "./src/fractol_image_100x100.png";
	width = 100;
	height = 100;

	if (access(img_logo, F_OK) != 0)
	{
		perror("fichire introuvable\n");
		return(false);
	}
	logo = mlx_xpm_file_to_image(data->mlx.mlx, img_logo, &width, &height);
	if (!logo)
	{
		printf("probleme logo %s et l = %p\n ", img_logo, logo);
		return(false);
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window, logo, 0, 0);
	return(true);
}

bool	render_pixel(t_game *data)
{
	int	color = 0x00FF0000;
	int	x;
	int	y;
	int	*pixel = (int *)data->mlx.address;

	int i;
	int c;
	int l;
	char **grid = data->map.grid;

	l = 0;
	while(l < 15){
	x = l * 12;
	while(x <= l * 12 + 10)
	{
		c = 0;
		y = 0;
		while(c < 14)
		{
			if(grid[c][l] && char_in_string(grid[c][l], "1"))
			{
				i = 0;
				while(i++ < 10)
					pixel[ (y++) * (data->mlx.line_length/4) + x] = color;
			}
			else
				y = y + 10;
			c++;
			y++;
		}
		x++;
	}
	l++;
	}
	//pixel[50 * (data->mlx.line_length/4) + 100] = color;
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window, data->mlx.img, 0, 0);
	return(true);

}

bool	render_loop(t_game *data)
{
	//render_logo(data);
	render_pixel(data);
//	render_logo(data);
	return(true);
}



