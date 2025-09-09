/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:07:05 by Charlye           #+#    #+#             */
/*   Updated: 2025/09/09 13:14:22 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	init_one_texture(t_game *data, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(data->mlx.mlx, path,
			&tex->tex_width, &tex->tex_height);
	if (!tex->img)
		return (false);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_length, &tex->endian);
	return (true);
}

bool	init_all_textures(t_game *data)
{
	if (!init_one_texture(data, &data->tex[NO], data->map.no_path))
		return (false);
	if (!init_one_texture(data, &data->tex[SO], data->map.so_path))
		return (false);
	if (!init_one_texture(data, &data->tex[WE], data->map.we_path))
		return (false);
	if (!init_one_texture(data, &data->tex[EA], data->map.ea_path))
		return (false);
	return (true);
}
