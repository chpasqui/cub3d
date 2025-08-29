/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:57:36 by Charlye           #+#    #+#             */
/*   Updated: 2025/08/29 19:26:24 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	// - Parcourir la map
	// -- poru recuperer les infos (identifants)
	// -- Parser les identifiants et verifier la validite
	// - Verifier ou commence la grille de la map (0 et 1) doit etre tout a la fin
	// -- Copier la grille dans map.grid
	// -- Verifier la validifite de map.grid

bool	char_in_string(char a, char *b)
{
	while (*b != '\0')
	{
		if (*b == a)
			return (true);
		b++;
	}
	return (false);
}

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


bool	print_char2(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		printf("%s\n", a[i]);
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

bool	parse_grid(t_map *map, int i)
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
	return (true);
}

bool	parse_color(t_map *map, int i)
{
	char	**tab;
	int		j;

	tab = ft_split(map->lines[i], ',');
	j = ft_atoi(tab[1]);
//	printf("F2 = %d\n", j);
	return (true);
}

bool	parse_file(t_map *map)
{
	int	i;

//	i = 0;
//	while (map->lines[i])
//	{
//		printf("lines : %s\n", map->lines[i]);
//		i++;
//	}
//	printf("\n");
	i = 0;
	while (map->lines[i])
	{
		if (char_in_string(map->lines[i][0], "01 "))
		{
			parse_grid(map, i);
			return (true);
		}
		else if (char_in_string(map->lines[i][0], "NSEW"))
		{
//			parse_texture_path(map, i);
		}
		else if (char_in_string(map->lines[i][0], "FC"))
		{
			parse_color(map, i);
		}
		else if (map->lines[i][0] == '\0')
		{
			//ignore empty lines
		}
		else
		{
			printf("passe_else\n");
			printf("\n");
			return (false);
		}
		i++;
//		printf("i++\n");
	}
	printf("\n");
	return (true);
}
