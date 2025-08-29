/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:36:28 by chpasqui          #+#    #+#             */
/*   Updated: 2025/08/29 11:13:19 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
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

/*---------MAIN-----------*/

//hook.c
int	mouse_hook (int button, int x, int y, t_game *data);
int	key_hook (int button, t_game *data);

//init.c
bool	init_mlx(t_game *data);
bool	init_value(t_game *data);

//main.c
int	close_window(t_game *data);

//render.c
bool	render_loop(t_game *data);

/*---------PARSING--------*/
int		count_lines(char *path, t_map *map);
bool	read_file(char *path, t_map *map);
bool	check_file_extension(char *path, int len);
bool	parse_arg(char *path, t_map *map);

//grid_close.c
bool	grid_close(t_map *map);
bool	algo_dfs(t_map *map, int r, int c);

//parse_file.c
bool	parse_file(t_map *map);
bool	save_grid(t_map *map, int i);
bool	print_char2(char **a);
bool	char_in_string(char a, char *b);



/*---------FREE_AND_ERRORS--------*/
void	free_map(t_map	*map);
void	free_mlx(t_mlx	*mlx);
void	free_game(t_game *data);
void	handle_map_error(t_map *map, char *msg);
void	handle_error(t_game *data, char *msg);
int	    clean_exit(t_game *data, int code);

#endif
