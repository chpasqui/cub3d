/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:08:43 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/08 12:01:51 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	algo_dfs(t_map *map, int row, int col)
{
	if (row < 0 || row >= map->height || col < 0 || !map->grid[row][col]
		|| map->grid[row][col] == ' ')
		return (false);
	if (map->grid[row][col] == '1' || map->pass_grid[row][col] == '1')
		return (true);
	map->pass_grid[row][col] = '1';
	if (!algo_dfs(map, row - 1, col))
		return (false);
	if (!algo_dfs(map, row + 1, col))
		return (false);
	if (!algo_dfs(map, row, col - 1))
		return (false);
	if (!algo_dfs(map, row, col + 1))
		return (false);
	return (true);
}

bool	save_grid(t_map *map, int i)
{
	int	j;

	j = 0;
	map->height = map->nb_lines - i;
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (false);
	while (map->lines[i] && c_in_s(map->lines[i][0], "01 "))
	{
		map->grid[j] = ft_strdup(map->lines[i]);
		grid_width(map, j);
		i++;
		j++;
	}
	map->grid[j] = NULL;
	if (i != map->nb_lines)
		handle_map_error(map, GRID_LAST);
	return (true);
}

bool	check_grid_char(t_map *map)
{
	int	i;
	int	j;
	int	nb_player;

	nb_player = 0;
	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (c_in_s(map->grid[i][j], "10 NSEW"))
				j++;
			else
				return (false);
			if (c_in_s(map->grid[i][j], "NSEW"))
				init_player(map, i, j);
			if (c_in_s(map->grid[i][j], "NSEW"))
				nb_player++;
		}
		i++;
	}
	if (nb_player != 1)
		return (false);
	return (true);
}

void	parse_grid(t_map *map, int i)
{
	save_grid(map, i);
	if (!check_grid_char(map))
		handle_map_error(map, GRID_CHAR);
	if (!grid_close(map))
		handle_map_error(map, GRID_CLOSE);
}
