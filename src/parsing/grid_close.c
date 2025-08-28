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
	int	i;
	int	dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};// SDU mettre ailleur?

//		printf("\n");
//		printf("r = %i, c = %i \n", r , c);
//		print_char2(map->pass_grid);
	if (!map->grid[r][c] || map->grid[r][c] == ' ')
		return (false);
	if (map->grid[r][c] == '1' || map->pass_grid[r][c] == '1')
		return (true);
	map->pass_grid[r][c] = '1';
//	printf("pass_grid\n");
	i = 0;
	while (i < 4)
	{
		if (!algo_dfs(map, r + dir[i][0], c + dir[i][1]))
			return (false);
		i++;
//		printf("i++\n");
	}
	return (true);
}
