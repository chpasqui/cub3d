/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:36:28 by chpasqui          #+#    #+#             */
/*   Updated: 2025/08/28 14:42:21 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef enum e_token
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	INVALID,
}	t_token;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*address;
	int		x_window;
	int		y_window;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map
{
	char	**lines;
	int		nb_lines;

	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;

	t_color	floor;
	t_color	ceiling;

	char	**grid;
	char	**pass_grid;
	int		height;
	int		width;

	int		player_x;
	int		player_y;
	char	player_dir;
}	t_map;

typedef struct s_game
{
	t_map   map;
	t_mlx	mlx;


}	t_game;

#endif
