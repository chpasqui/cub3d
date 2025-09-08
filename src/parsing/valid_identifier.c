/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:54:50 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/08 12:03:14 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_token	define_token(char *line)
{
	if (!strncmp(line, "NO ", 3))
		return (NO);
	if (!strncmp(line, "SO ", 3))
		return (SO);
	if (!strncmp(line, "WE ", 3))
		return (WE);
	if (!strncmp(line, "EA ", 3))
		return (EA);
	if (!strncmp(line, "F ", 2))
		return (F);
	if (!strncmp(line, "C ", 2))
		return (C);
	else
		return (INVALID);
}

bool	no_duplicates(t_map *map, t_token token)
{
	if (token == NO && !map->no_path)
		return (true);
	if (token == SO && !map->so_path)
		return (true);
	if (token == WE && !map->we_path)
		return (true);
	if (token == EA &&!map->ea_path)
		return (true);
	if (token == C && map->ceiling.r == -1)
		return (true);
	if (token == F && map->ceiling.r == -1)
		return (true);
	return (false);
}

bool	all_identifiers(t_map *map)
{
	if (map->no_path && map->so_path && map->we_path
		&& map->ea_path && map->ceiling.r != -1 && map->floor.r != -1)
		return (true);
	return (false);
}

bool	line_is_identifier(char *line, t_map *map)
{
	if (!line || !*line)
		return (false);
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
		|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
	{
		if (line[2] != ' ')
			handle_map_error(map, MISSING_SPACE);
		return (true);
	}
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
	{
		if (line[1] != ' ')
			handle_map_error(map, MISSING_SPACE);
		return (true);
	}
	return (false);
}
