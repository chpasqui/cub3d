/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:36:28 by chpasqui          #+#    #+#             */
/*   Updated: 2025/08/28 17:47:35 by chpasqui         ###   ########.fr       */
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


/*---------INIT.C-------------*/
void	init_map(t_map *map);

/*---------PARSING--------*/
int		count_lines(char *path, t_map *map);
bool	read_file(char *path, t_map *map);
bool	check_file_extension(char *path, int len, char *extension);
bool	parse_arg(char *path, t_map *map);

//parse_identifer.c
int		skip_space(char *line);
bool	line_is_identifier(char *line, t_map *map);
bool	parse_file2(t_map *map);


//grid_close.c
bool	grid_close(t_map *map);
bool	algo_dfs(t_map *map, int r, int c);

//parse_file.c
bool	char_in_string(char a, char *b);
bool	parse_file(t_map *map);
bool	save_grid(t_map *map, int i);
bool	print_char2(char **a);
void	parse_grid(t_map *map, int i);

/*---------FREE_AND_ERRORS--------*/
void	free_str_array(char **arr);
void	free_map(t_map	*map);
void	free_mlx(t_mlx	*mlx);
void	free_game(t_game *data);
void	handle_map_error(t_map *map, char *msg);
void	handle_error(t_game *data, char *msg);
int	    clean_exit(t_game *data, int code);


/*-----------UTILS----------------*/

//trim.c
char	*left_trim(char *str);
void	right_trim(char *str, int len);
char	*trim_all_spaces(char *str);

#endif
