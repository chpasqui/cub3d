/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid_tool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:08:43 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/09 13:47:10 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	grid_width(t_map *map, int j)
{
	int	l;

	l = ft_strlen(map->grid[j]);
	if (l > map->width)
		map->width = l;
}

void	init_player(t_map *map, int i, int j)
{
	map->player_x = j;
	map->player_y = i;
	map->player_dir = map->grid[i][j];
}

bool	init_pass_grid(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->pass_grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (false);
	while (map->grid[i])
	{
		map->pass_grid[i] = ft_strdup(map->grid[i]);
		j = 0;
		while (map->pass_grid[i][j])
		{
			map->pass_grid[i][j] = '0';
			j++;
		}
		i++;
	}
	map->pass_grid[i] = NULL;
	return (true);
}

bool	grid_close(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (!init_pass_grid(map))
				return (false);
			if (c_in_s(map->grid[i][j], "0NSEW") && !algo_dfs(map, i, j))
				return (false);
			j++;
			if (map->pass_grid)
				free_str_array(map->pass_grid);
		}
		i++;
	}
	return (true);
}

bool	grid_close2(t_map *map)
{
	if (c_in_s(map->grid[1][1], "0NSEW") && !algo_dfs(map, 1, 1))
		return (false);
	if (map->pass_grid)
		free_str_array(map->pass_grid);
	return (true);
}
