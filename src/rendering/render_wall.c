/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:43:43 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/08 18:08:45 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_pixel_from_texture(t_texture *tex, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = tex->addr + (y * tex->line_length + x * (tex->bpp / 8));
	color = *(int *)pixel;
	return (color);
}

int	define_wall(t_ray *ray)
{
	if (ray->side == 0 && ray->raydirx > 0)
		return (EA);
	else if (ray->side == 0 && ray->raydirx < 0)
		return (WE);
	else if (ray->side == 1 && ray->raydiry > 0)
		return (SO);
	else
		return (NO);
}

void	render_wall(t_game *data, int x, int tex_side)

{
	double		wall_y;
	int			tex_y;
	int			color;
	t_render	*render;
	t_texture	*tex;

	tex = &data->tex[tex_side];
	render = &data->render;
	render->ratio = (double)tex->tex_height / data->render.wall_height;
	render->tex_pos = (render->draw_start - data->mlx.y_window / 2
			+ render->wall_height / 2) * render->ratio;
	wall_y = data->render.draw_start;
	while (wall_y < data->render.draw_end)
	{
		tex_y = (int)render->tex_pos;
		render->tex_pos += render->ratio;
		color = get_pixel_from_texture(tex, data->render.tex_x, tex_y);
		put_pixel_in_image(&data->mlx, x, (int)wall_y, color);
		wall_y++;
	}
}
