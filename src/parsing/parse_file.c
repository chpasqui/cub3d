/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:57:36 by Charlye           #+#    #+#             */
/*   Updated: 2025/08/29 12:23:01 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_file(t_map *map)
{
	int	i;
	int	s;

	i = 0;
	while (map->lines[i])
	{
		s = skip_space(map->lines[i]);
		if (map->lines[i][s] == '\0')
			i++;
		else if (line_is_identifier(&map->lines[i][s], map))
		{
			parse_identifier(map, &map->lines[i][s]);
			i++;
		}
		else if (char_in_string(map->lines[i][s], "01"))
			break ;
		else
			handle_map_error(map, WRONG_IDENTIFIER);
	}
	if (!map->lines[i])
		handle_map_error(map, MISSING_GRID);
	parse_grid(map, i);
	if (!all_identifiers(map))
		handle_map_error(map, MISSING_IDENTIFIER);
	return (true);
}

