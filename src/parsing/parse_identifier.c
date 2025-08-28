/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:20:04 by Charlye           #+#    #+#             */
/*   Updated: 2025/08/28 11:13:13 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include "cub3d.h"

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
	
}

void	parse_identifier(t_map *map, )
{
	
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
		else if (line_is_identifier(&map->lines[i][s]))
		{
			parse_identifier(&map->lines[i][s]);
			i++;
		}
		else if (char_in_string(map->lines[i][s], "01"))
		{
			if (!all_identifiers(map))
				handle_error(map, NOT_ENOUGH_IDENTIFIER);
			break ;
		}
		else
			handle_error(map, WRONG_IDENTIFIER);
	}
	parse_grid(map, i)
	return (true);
}

// faudrait ajouter dans parse_grid la condition if !map->lines[i] --> handle error NO_MAP_FOUND (pas assez de ligne)
