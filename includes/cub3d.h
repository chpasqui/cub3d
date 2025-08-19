/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:36:28 by chpasqui          #+#    #+#             */
/*   Updated: 2025/08/19 17:00:31 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# include "cub3d_struct.h"
# include "keycodes.h"
# include "error.h"

# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>

/*---------PARSING--------*/
int		count_lines(char *path, t_map *map);
bool	read_file(char *path, t_map *map);
bool	check_file_extension(char *path, int len);
bool	parse_arg(char *path, t_map *map);

bool	parse_file(t_map *map);

/*---------FREE_AND_ERRORS--------*/
void	free_map(t_map	*map);
void	free_mlx(t_mlx	*mlx);
void	free_game(t_game *data);
void	handle_map_error(t_map *map, char *msg);
void	handle_error(t_game *data, char *msg);



#endif