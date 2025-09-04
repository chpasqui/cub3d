/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:43:43 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/04 16:02:26 by chpasqui         ###   ########.fr       */
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
	render->tex_x = render->wall_x * data->tex->tex_width;
	render->draw_start = (data->mlx.y_window / 2) - (render->wall_height / 2);
	render->draw_end = (data->mlx.y_window / 2) + (render->wall_height / 2);
}


void	define_wall(t_ray *ray, t_texture *tex)
{
	if (ray->side == 0 && ray->raydirx > 0)
		tex->tex_side = EA;
	else if (ray->side == 0 && ray->raydirx < 0)
		tex->tex_side = WE;
	else if (ray->side == 1 && ray->raydiry > 0)
		tex->tex_side = SO;
	else
		tex->tex_side = NO;
}

void	align_texutre(t_game *data)
{
	double	ratio;
	double	tex_pos;
	int		wall_y;

	wall_y = 0;
	ratio = data->render.wall_height / data->tex->tex_height;
	tex_pos = data->mlx.y_window / 2 - data->render.wall_height / 2;
	while (wall_y < data->render.draw_end)
	{
		wall_y = data->render.draw_start + tex_pos * ratio;
		mlx_xpm_to_image(data->mlx.mlx, data->tex[data->tex->tex_side].img,
			&data->tex->tex_width, &data->tex->tex_height);
		wall_y++;
	}

}
void	render_wall(t_game *data)

{	
	t_texture *tex;

	define_wall(&data->ray, &data->tex);
	tex = &data->tex[data->tex->tex_side];
	align_texture()
	// aligner la texture selon le mur
	// if data->texture->side == "north"
		render la texture en north... pixel par pixel?
	
}

void	select_color_texture(t_game *data);
{
	int	y;

	y = 0;
	while (y >= 0 && y <= data->mlx.y_window)
	{
		if (y >= data->render.draw_start && (y <= data->render.draw_end))
			render_wall(data);
		else if (y < render->data.draw_start && data->render.draw_end >= 0)
			render_ceiling(data);
		else if (y > data->render.draw_end)
			render_floor(data);
		y++;
	}
}









