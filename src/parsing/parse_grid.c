/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:08:43 by chpasqui          #+#    #+#             */
/*   Updated: 2025/08/29 12:10:34 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

	return (algo_dfs(map, 1, 1));
}


bool	algo_dfs(t_map *map, int r, int c)
{
	int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};//mettre ailleur?
	int	i;

	//printf("\n");
	//printf("r = %i, c = %i \n", r , c);
	//print_char2(map->pass_grid);

	if (!map->grid[r][c] || map->grid[r][c] == ' ')
		return (false);
	if (map->grid[r][c] == '1' || map->pass_grid[r][c] == '1')
		return (true);

	 map->pass_grid[r][c] = '1';
	//	 printf("pass_grid\n");
	i = 0;
	while (i < 4)
	{
		if (!algo_dfs(map, r + dir[i][0],c + dir[i][1]))
			return (false);
		i++;
		//		printf("i++\n");
	}
	//	printf("\n");
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
		i++;
		j++;
	}
	map->grid[j] = NULL;
	if (i != map->nb_lines)
		handle_map_error(map, GRID_LAST);
	return (true);
}

bool	check_grid_char(char **grid)
{
	int	i;
	int	j;
	int	nb_player;

	nb_player = 0;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (char_in_string(grid[i][j], "10 NSEW"))
				j++;
			else
				return (false);
			if (char_in_string(grid[i][j], "NSEW"))
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
	if (!check_grid_char(map->grid))
		handle_map_error(map, GRID_CHAR);
	if (grid_close(map) != true)
		handle_map_error(map, GRID_CLOSE);
	printf("\n");
	print_char2(map->grid);
	printf("\n");
	print_char2(map->pass_grid);
	printf("\n");
}
