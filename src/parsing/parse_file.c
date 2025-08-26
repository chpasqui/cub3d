/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:57:36 by Charlye           #+#    #+#             */
/*   Updated: 2025/08/26 13:13:07 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_file(t_map *map)
{
	// - Parcourir la map
	// -- poru recuperer les infos (identifants)
	// -- Parser les identifiants et verifier la validite
	// - Verifier ou commence la grille de la map (0 et 1) doit etre tout a la fin
	// -- Copier la grille dans map.grid
	// -- Verifier la validifite de map.grid


	int i;

	i = 0;
	while (map->file[i])
	{
		printf("file : %c", map->file[i]);
		i++;
	}

	i = 0;
	while (map->file[i])
	{
		if (map->file[i][0] != '0' || map->file[i][0] != '1' || map->file[i][0] != ' ')
		{
			parse_grid(map, i);
			return(0);
		}
		if (map->file[i][0] != 'N' || map->file[i][0] != 'S')
		{
			parse_
		}
			i++;
	}


