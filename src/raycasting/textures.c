/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:43:43 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/05 11:49:23 by Charlye          ###   ########.fr       */
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

int	get_pixel_from_texture(t_texture *tex, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = tex->addr + (y * tex->line_length + x * (tex->bpp / 8));
	color = *(int *)pixel;
	return (color);
}

void	render_wall(t_game *data, int x)

{
	double		ratio;
	int			wall_y;
	int			tex_y;
	int			color;
	t_texture	*tex;

	define_wall(&data->ray, &data->tex);
	tex = &data->tex[data->tex->tex_side];
	ratio = data->render.wall_height / data->tex->tex_height;
	wall_y = data->render.draw_start;
	while (wall_y < data->render.draw_end)
	{
		tex_y = (int)((wall_y - data->render.draw_start) / ratio);
		color = get_pixel_from_texture(tex, data->render.tex_x, tex_y);
		put_pixel_in_image(&data->mlx, data->x,
			wall_y, color);
		wall_y++;
	}
}

void	render_game(t_game *data, int x)
{
	render_ceiling(data, x, 0, data->render.draw_start);
	render_wall(data, x);
	render_floor(data, x, data->render.draw_end, data->mlx.y_window);
}










