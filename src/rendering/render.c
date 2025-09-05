/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:00:14 by Charlye           #+#    #+#             */
/*   Updated: 2025/09/05 14:01:14 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	prepare_render_values(t_game *data)
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
	render->tex_x = render->wall_x * data->tex->tex_width;
	render->draw_start = (data->mlx.y_window / 2) - (render->wall_height / 2);
	render->draw_end = (data->mlx.y_window / 2) + (render->wall_height / 2);
}

void	render_game(t_game *data, int x)
{
	render_ceiling(data, x, 0, data->render.draw_start);
	render_wall(data, x);
	render_floor(data, x);
}