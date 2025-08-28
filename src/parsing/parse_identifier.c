/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:20:04 by Charlye           #+#    #+#             */
/*   Updated: 2025/08/28 12:00:34 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_space(char *line)
{
	int	s;

	s = 0;
	while (line[s] == ' ')
		s++;
	return (s);
}

bool	all_identifiers(t_map *map)
{
	(void)*map;
	return (true);
}

void	parse_identifier(t_map *map)
{
	(void)*map;
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

bool	parse_file2(t_map *map)
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
			printf("yes");
			//parse_identifier(&map->lines[i][s]);
			i++;
		}
		// else if (char_in_string(map->lines[i][s], "01"))
		// {
		// 	if (!all_identifiers(map))
		// 		handle_error(map, NOT_ENOUGH_IDENTIFIER);
		// 	break ;
		// }
		else
			handle_map_error(map, WRONG_IDENTIFIER);
	}
	//parse_grid(map, i);
	return (true);
}

// faudrait ajouter dans parse_grid la condition if !map->lines[i] --> handle error NO_MAP_FOUND (pas assez de ligne)
