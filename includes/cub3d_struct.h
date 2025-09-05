/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:36:28 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/05 19:57:06 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include <stdbool.h>

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

typedef struct s_minimap
{
	int		square_size;
	int		width;
	int		height;
	int		offset_x;
	int		offset_y;

	int		color_wall;
	int		color_floor;
	int		color_player;
	int		color_ray;

	bool	show;
}	t_minimap;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		tex_width;
	int		tex_height;
}	t_texture;

typedef struct s_ray
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		side;
	int		hit;
	double	time;
	double	oldtime;
	double	frametime;
	double	movespeed;
	double	rotspeed;
	double	bord;
}	t_ray;

typedef struct s_render
{
	double	wall_height;
	double	wall_x;
	int	tex_x;
	int	draw_start;
	int	draw_end;
}	t_render;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		olddir_x;
	double		oldplane_x;
}	t_player;

typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	up;
	int	down;
	int	left;
	int	right;
}	t_key;

typedef struct s_game
{
	t_map		map;
	t_mlx		mlx;
	t_minimap	minimap;
	t_player	player;
	t_ray		ray;
	t_render	render;
	t_texture	tex[4];
	t_key		key;
}	t_game;

#endif
