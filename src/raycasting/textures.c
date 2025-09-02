/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:43:43 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/02 18:03:07 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_values_for_test(t_game	*data)
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

// calculation de la texture : comprendre comment cela fonctionne 
void	prepare_wall_values(t_game *data)
{
	double perpwalldist;

	perpwalldist = data->ray.perpwalldist;
	init_values_for_test(data);
	data->wall.wall_height = perpwalldist * data->mlx.y_window;
	if (data->ray.side == 0)
		data->wall.wall_x = data->player.pos_y + perpwalldist * data->ray.raydiry;
	else
		data->wall.wall_x = data->player.pos_x + perpwalldist * data->ray.raydirx;
	data->wall.wall_x -= floor(data->wall.wall_x);
	data->wall.tex_x = data->wall.wall_x * data->tex.tex_width;
	data->wall.draw_start = (data->mlx.y_window / 2) - (data->wall.wall_height / 2);
	data->wall.draw_end = (data->mlx.y_window / 2) + (data->wall.wall_height / 2);
}

}

void	define_draw_end_start






