/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:07:05 by Charlye           #+#    #+#             */
/*   Updated: 2025/09/05 14:25:42 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_one_texture(t_game *data, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(data->mlx.mlx, path,
			&tex->tex_width, &tex->tex_height);
	if (!tex->img)
		handle_map_error(data, IMG_FAILED);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_length, &tex->endian);
}

void	init_all_texture(t_game *data)
{
	init_one_texture(data, &data->tex[NO], data->map.no_path);
	init_one_texture(data, &data->tex[SO], data->map.so_path);
	init_one_texture(data, &data->tex[WE], data->map.we_path);
	init_one_texture(data, &data->tex[EA], data->map.ea_path);
}