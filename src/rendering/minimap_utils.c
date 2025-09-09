/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:54:38 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/09 14:09:12 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calc_pos_y_minimap(t_game *data, int view_rows)
{
	int	py;

	py = data->minimap.offset_y
		+ (data->player.pos_y - (data->map.player_y - view_rows / 2))
		* data->minimap.square_size;
	return (py);
}

int	calc_pos_x_minimap(t_game *data, int view_cols)
{
	int	px;

	px = data->minimap.offset_x
		+ (data->player.pos_x - (data->map.player_x - view_cols / 2))
		* data->minimap.square_size;
	return (px);
}
