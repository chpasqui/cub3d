/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:20:04 by Charlye           #+#    #+#             */
/*   Updated: 2025/08/29 11:56:58 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	verify_color_value(char **tab)
{
	int	i;
	int	value;

	i = 0;
	while (tab[i])
	{
		value = ft_atoi(tab[i]);
		if (value < 0 || value > 255)
			return (false);
		i++;
	}
	if (i != 3)
		return (false);
	return (true);
}

void	parse_color(t_map *map, char *value, t_token token)
{
	char	**tab;

	value = trim_all_spaces(value);
	if (!*value)
		handle_map_error(map, MISSING_COLOR_VALUES);
	tab = ft_split(value, ',');
	if (!tab)
		handle_map_error(map, MALLOC_FAIL);
	if (!verify_color_value(tab))
		handle_map_error(map, INVALID_COLOR);
	if (token == C)
	{
		map->ceiling.r = ft_atoi(tab[0]);
		map->ceiling.g = ft_atoi(tab[1]);
		map->ceiling.b = ft_atoi(tab[2]);
	}
	if (token == F)
	{
		map->floor.r = ft_atoi(tab[0]);
		map->floor.g = ft_atoi(tab[1]);
		map->floor.b = ft_atoi(tab[2]);
	}
	free_str_array(tab);
}

void	save_texture_path(t_map *map, t_token token, char *path)
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
	int		len;
	int		fd;
	char	*whole_path;

	path = left_trim(path);
	if (!*path)
		handle_map_error(map, MISSING_TEXTURE_PATH);
	len = ft_strlen(path);
	right_trim(path, len);
	if (!check_file_extension(path, len, "xpm"))
		handle_map_error(map, BAD_EXTENSION_XPM);
	whole_path = ft_strjoin("textures/", path);
	fd = open(whole_path, O_RDONLY);
	if (fd == -1)
		handle_map_error(map, CANNOT_OPEN_XPM);
	close(fd);
	save_texture_path(map, token, path);
}
 
void	parse_identifier(t_map *map, char *line)
{
	t_token	token;

	token = define_token(line);
	if (!no_duplicates(map, token))
		handle_map_error(map, DUPLICATE_IDENTIFIER);
	if (token == NO || token == SO || token == WE || token == EA)
		parse_texture(map, line + 3, token);
	if (token == C || token == F)
		parse_color(map, line + 2, token);
}

