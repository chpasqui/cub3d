/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:08:43 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/01 08:35:58 by Charlye          ###   ########.fr       */
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

bool	grid_close(t_map *map)
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
	return (algo_dfs(map, 2, 2)); //attention a revoir
}

bool	algo_dfs(t_map *map, int l, int c)
{
	int	i;
	int	dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};// SDU mettre ailleur?

	//	printf("\n");
	//	printf("l = %i, c = %i, map->height = %i\n", l , c, map->height);
	//	print_char2(map->pass_grid);
	if (l < 0 || l >= map->height || c < 0 || !map->grid[l][c] || map->grid[l][c] == ' ')
		return (false);
	if (map->grid[l][c] == '1' || map->pass_grid[l][c] == '1')
		return (true);
	map->pass_grid[l][c] = '1';
	i = 0;
	while (i < 4)
	{
		if (!algo_dfs(map, l + dir[i][0], c + dir[i][1]))
			return (false);
		i++;
	}
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
//	printf("\n");
//	print_char2(map->grid);
//	printf("\n");
//	print_char2(map->pass_grid);
//	printf("\n");
}
