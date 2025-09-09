/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:36:41 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/09 15:39:31 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_color_ceiling(t_map *map, char **tab)
{
		map->ceiling.r = ft_atoi(tab[0]);
		map->ceiling.g = ft_atoi(tab[1]);
		map->ceiling.b = ft_atoi(tab[2]);
}

void	init_color_floor(t_map *map, char **tab)
{
		map->floor.r = ft_atoi(tab[0]);
		map->floor.g = ft_atoi(tab[1]);
		map->floor.b = ft_atoi(tab[2]);
}
