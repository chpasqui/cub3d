/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:36:28 by chpasqui          #+#    #+#             */
/*   Updated: 2025/08/29 12:16:33 by chpasqui         ###   ########.fr       */
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
//init.c
bool	init_mlx(t_game *data);
bool	init_value(t_game *data);

//render.c
bool	render_loop(t_game *data);

/*-----------INIT.C-----------*/
void	init_map(t_map *map);

/*-----------PARSING-----------*/

//parse_arg.c
int		count_lines(char *path, t_map *map);
bool	read_file(char *path, t_map *map);
bool	check_file_extension(char *path, int len, char *extension);
bool	parse_arg(char *path, t_map *map);

//parse_file.c
bool	parse_file(t_map *map);

//parse_identifer.c
bool	verify_color_value(char **tab);
void	parse_color(t_map *map, char *value, t_token token);
void	save_texture_path(t_map *map, t_token token, char *path);
void	parse_texture(t_map *map, char *path, t_token token);
void	parse_identifier(t_map *map, char *line);

//valid_identifier.c
bool	line_is_identifier(char *line, t_map *map);
bool	all_identifiers(t_map *map);
bool	no_duplicates(t_map *map, t_token token);
t_token	define_token(char *line);

//parse_grid.c
bool	algo_dfs(t_map *map, int r, int c);
bool	check_grid_char(char **grid);
bool	save_grid(t_map *map, int i);
bool	grid_close(t_map *map);
void	parse_grid(t_map *map, int i);

/*-----------FREE_AND_ERRORS-----------*/
void	free_str_array(char **arr);
void	free_map(t_map	*map);
void	free_mlx(t_mlx	*mlx);
void	free_game(t_game *data);
void	handle_map_error(t_map *map, char *msg);
void	handle_error(t_game *data, char *msg);
int	    clean_exit(t_game *data, int code);

/*-----------UTILS-----------*/

//trim.c
char	*left_trim(char *str);
void	right_trim(char *str, int len);
char	*trim_all_spaces(char *str);

//debug.c
bool	print_char2(char **a);

//other.c
bool	char_in_string(char a, char *b);
int		skip_space(char *line);

#endif
