/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:08:43 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/01 12:22:21 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	grid_width(t_map * map, int j)
{
	int	l;

	l = ft_strlen(map->grid[j]);
	if (l > map->width)
		map->width = l;
}

void init_player(t_map *map, int i, int j)
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
	return(true);
}

bool	grid_close(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			init_pass_grid(map);
			if (char_in_string(map->grid[i][j], "0NSEW") && !algo_dfs(map, i, j))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	algo_dfs(t_map *map, int row, int col)
{
	//	printf("\n");
	//	printf("l = %i, c = %i, map->height = %i\n", l , c, map->height);
	//	print_char2(map->pass_grid);
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
	while (map->lines[i] && char_in_string(map->lines[i][0], "01 "))
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
			if (char_in_string(map->grid[i][j], "10 NSEW"))
				j++;
			else
				return (false);
			if (char_in_string(map->grid[i][j], "NSEW"))
			{
				init_player(map, i, j);
				nb_player++;
			}
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
	printf("\n");
	print_char2(map->grid);
	printf("\n");
	print_char2(map->pass_grid);
	printf("\n");
}
