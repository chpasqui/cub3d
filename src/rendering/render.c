/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:00:14 by Charlye           #+#    #+#             */
/*   Updated: 2025/09/08 14:32:28 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	prepare_render_values(t_game *data, int tex_side)
{
	double		perpwalldist;
	t_render	*render;

	render = &data->render;
	perpwalldist = data->ray.perpwalldist;
	render->wall_height = data->mlx.y_window / perpwalldist;
	if (data->ray.side == 0)
		render->wall_x = data->player.pos_y + perpwalldist * data->ray.raydiry;
	else
		render->wall_x = data->player.pos_x + perpwalldist * data->ray.raydirx;
	render->wall_x -= floor(render->wall_x);
	render->tex_x = render->wall_x * data->tex[tex_side].tex_width;
	render->draw_start = (data->mlx.y_window / 2) - (render->wall_height / 2);
	if (render->draw_start < 0)
		render->draw_start = 0;
	render->draw_end = (data->mlx.y_window / 2) + (render->wall_height / 2);
	if (render->draw_end >= data->mlx.y_window)
		render->draw_end = data->mlx.y_window - 1;
}

void	render_game(t_game *data)
{
	int	x;
	int	tex_side;

	x = 0;
	while (x < data->mlx.x_window)
	{
		init_ray(data, x);
		algo_dda(data);
		calc_perpwalldist(data);
		tex_side = define_wall(&data->ray);
		if (tex_side < 0 || tex_side > 3)
			tex_side = 0;
		prepare_render_values(data, tex_side);
		render_ceiling(data, x, 0);
		render_wall(data, x, tex_side);
		render_floor(data, x, data->render.draw_end);
		x++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window,
		data->mlx.img, 0, 0);
}

/*printf("px=%.2f  py=%.2f  dix=%.2f  diy=%.2f  plx=%.2f  
ply=%.2f  dex=%2.f  dey=%2.f  six=%2.f  siy=%2.f\n", 
data->player.pos_x, data->player.pos_y, data->player.dir_x, 
data->player.dir_y, data->player.plane_x, data->player.plane_y
,data->ray.deltadistx, data->ray.deltadisty, data->ray.sidedistx,
 data->ray.sidedisty);
*/