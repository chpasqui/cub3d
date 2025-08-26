/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:57:36 by Charlye           #+#    #+#             */
/*   Updated: 2025/08/26 14:50:24 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	// - Parcourir la map
	// -- poru recuperer les infos (identifants)
	// -- Parser les identifiants et verifier la validite
	// - Verifier ou commence la grille de la map (0 et 1) doit etre tout a la fin
	// -- Copier la grille dans map.grid
	// -- Verifier la validifite de map.grid

bool parse_color(t_map *map, int i)
{
	char** tab;
	int i;

	tab = ft_split(line[i], ',');
	i = ft_atoi(tab[1]);
	printf("F2 = %d\n", i);

	return(true);
}
	
bool	parse_file(t_map *map)
{
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
		}
		else if (map->file[i][0] == 'N' || map->file[i][0] == 'S' || map->file[i][0] == 'E' || map->file[i][0] == 'W')
		{
			parse_texture_path(map, i);
		}
		else if (map->file[i][0] == 'F' || map->file[i][0] == 'C')
		{
			parse_color(map, i);
		}
		else if (map->file[i][0] == '\n')
		{
			//ignore empty lines
		}
		else
		{
			return (false);
		}
		i++;
	}
	return(true);
}

