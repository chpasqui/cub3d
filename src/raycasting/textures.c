/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:43:43 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/03 18:39:51 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_values_for_test(t_game	*data)
{
	ft_bzero(&data->ray, sizeof(t_ray));
	ft_bzero(&data->player, sizeof(t_player));
	data->player.pos_x = 2.5;
	data->player.pos_y = 4.5;
	data->ray.perpwalldist = 4;
	data->ray.raydirx = 2;
	data->ray.raydiry = 5;
	data->ray.side = 1;
}

void	prepare_render_values(t_game *data)
{
	double		perpwalldist;
	t_render	*render;

	render = &data->render;

	perpwalldist = data->ray.perpwalldist;
	init_values_for_test(data);
	render->wall_height = data->mlx.y_window / perpwalldist;
	if (data->ray.side == 0)
		render->wall_x = data->player.pos_y + perpwalldist * data->ray.raydiry;
	else
		render->wall_x = data->player.pos_x + perpwalldist * data->ray.raydirx;
	render->wall_x -= floor(render->wall_x);
	render->tex_x = render->wall_x * data->tex.tex_width;
	render->draw_start = (data->mlx.y_window / 2) - (render->wall_height / 2);
	render->draw_end = (data->mlx.y_window / 2) + (render->wall_height / 2);
}

void	select_color_texture(t_game *data);
{
	int	y;
	
	y = 0,
	while (y >= 0 && y <= data->mlx.y_window)
	{
		if (y >= data->render.draw_start && y =< drawend)
		define_wall(data);
	else if (data->ray.mapy < drawstart && data->ray.mapy >= 0)
		render_ceiling(data);
	else if (data->ray.mapy > drawend && data->ray.mapy < mlx.y_window)
		render_floor(data);
	else
		handle_error();
	}
}









