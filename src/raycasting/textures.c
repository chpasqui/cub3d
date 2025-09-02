/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:43:43 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/02 14:30:56 by chpasqui         ###   ########.fr       */
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

texnum = map->grid[ray->mapX][ray->mapY] - 1;


// etape 5 selon tes notes 

// wallx a quoi ca correspond exactement ? car si cest un mur ou side == 1, alors c-est les y du mur mais
// toujours les x de la texture. donc quel est la diff avec texX ?
void	set_value_wall_x(t_game *data)
{
	t_ray		*ray;
	t_player	*player;
	t_texture	*tex;

	*ray = data->ray;
	*player = data->player;
	*tex = data->tex;
	init_values_for_test(data);
	if (data->ray.side == 0)
		tex->wallx = player->pos_y + ray->perpwalldist * ray->raydiry;
	else
		tex->wallx = player->pos_x + ray->perpwalldist * ray->raydirx;
	tex->wallx -= floor(tex->wallx); // floor sort l integral la plus proche exemple floor(6.5) = 6
	
}

void	set_x_on_texture(t_game *game)
{
	
}






