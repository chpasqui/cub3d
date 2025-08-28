/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:20:04 by Charlye           #+#    #+#             */
/*   Updated: 2025/08/28 13:27:15 by Charlye          ###   ########.fr       */
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
void	save_path(t_map *map, t_token token, char *path)
{	
	char	*tmp;

	tmp = ft_strdup(path);
	if (!tmp)
		handle_map_error(map, MALLOC_FAIL);
	if (token == NO)
		map->no_path = tmp;
	else if (token == SO)
		map->so_path = tmp;
	else if (token == WE)
		map->we_path = tmp;
	else if (token == EA)
		map->ea_path = tmp;
}
void	parse_texture(t_map *map, char *path, t_token token)
{
	int	len;
	int	fd;

	path = left_trim(path);
	if (!*path)
		handle_map_error(map, MISSING_TEXTURE_PATH);
	len = ft_strlen(path);
	right_trim(path, len);
	if (!check_file_extension(path, len, "xpm"))
		handle_map_error(map, BAD_EXTENSION_XPM);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		handle_map_error(map, CANNOT_OPEN_XPM);
	close(fd);
	save_path(map, token, path)
}

void	parse_identifier(t_map *map, char *line)
{
	t_token	token;

	token = define_token(line);
	if (!no_duplicate(map, token))
		handle_map_error(map, DUPLICATE_IDENTIFIER);
	if (token == NO || token == SO || token == WE || token == EA)
		parse_texture(map, line + 3, token);
	if (token == C || token == F)
		parse_color(map, line + 2, token);
}

	// verifier que la variable nexiste pas deja
	// separer en 2, parse texture et parse color
	// pour les textures :
	// verifier que le fichier termine par .xpm
	// verifier quil peut souvri
	// enregistrer dans la variable correspondante dans la struct
	// pour les couleurs:
	// verifier que cest des digits ou des virgules
	// separer par un ft split 
	// verifier quil y a bien 3 variables
	// verifier la validite des variable entre 0 et 255
	// enregistrer les variables correspondantes dans la struct


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
			parse_identifier(map, &map->lines[i][s]);
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
