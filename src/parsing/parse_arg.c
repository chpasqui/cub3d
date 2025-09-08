/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:57:53 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/08 19:09:28 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_lines(char *path, t_map *map)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		handle_map_error(map, CANNOT_OPEN);
	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free (line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static bool	read_file(char *path, t_map *map)
{
	int		i;
	int		fd;
	char	*line;

	map->nb_lines = count_lines(path, map);
	if (map->nb_lines == 0)
		handle_map_error(map, EMPTY_FILE);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		handle_map_error(map, CANNOT_OPEN);
	map->lines = malloc(sizeof(char *) * (map->nb_lines + 1));
	if (!map->lines)
		return (false);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->lines[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map->lines[i] = NULL;
	close(fd);
	return (true);
}

bool	check_file_extension(char *path, int len, char *extension)
{
	int	i;

	i = len - 1;
	if (!strncmp(extension, "cub", 3))
	{
		if (path[i] != 'b' || path[i - 1] != 'u' || path[i -2] != 'c'
			|| path[i - 3] != '.')
			return (false);
	}
	else if (!ft_strncmp(extension, "xpm", 3))
	{
		if (path[i] != 'm' || path[i - 1] != 'p' || path[i -2] != 'x'
			|| path[i - 3] != '.')
			return (false);
	}
	return (true);
}

bool	parse_arg(char *path, t_map *map)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5)
		handle_map_error(map, INVALID_NAME);
	if (!check_file_extension(path, len, "cub"))
		handle_map_error(map, BAD_EXTENSION_CUB);
	if (!read_file(path, map))
		return (false);
	if (!parse_file(map))
		return (false);
	return (true);
}
