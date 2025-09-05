/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:32:29 by sydubois          #+#    #+#             */
/*   Updated: 2025/09/04 20:31:39 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	move_map_up(t_game *data)
{
	int			l;
	int			c;
	t_player	*p;

	p = &data->player;
	l = (int)(p->pos_x + p->dir_x * data->ray.movespeed * data->ray.bord);
	c = (int)p->pos_y;
	if (!char_in_string(data->map.grid[c][l], "1"))
		p->pos_x += p->dir_x * data->ray.movespeed;
	l = (int)p->pos_x;
	c = (int)(p->pos_y + p->dir_y * data->ray.movespeed * data->ray.bord);
	if (!char_in_string(data->map.grid[c][l], "1"))
		p->pos_y += p->dir_y * data->ray.movespeed;
	return (true);
}

bool	move_map_down(t_game *data)
{
	int			l;
	int			c;
	t_player	*p;

	p = &data->player;
	l = (int)(p->pos_x - p->dir_x * data->ray.movespeed * data->ray.bord);
	c = (int)p->pos_y;
	if (!char_in_string(data->map.grid[c][l], "1"))
		p->pos_x -= p->dir_x * data->ray.movespeed;
	l = (int)p->pos_x;
	c = (int)(p->pos_y - p->dir_y * data->ray.movespeed * data->ray.bord);
	if (!char_in_string(data->map.grid[c][l], "1"))
		p->pos_y -= p->dir_y * data->ray.movespeed;
	return (true);
}

bool	move_map_left(t_game *data)
{
	int			l;
	int			c;
	t_player	*p;

	p = &data->player;
	l = (int)(p->pos_x + p->dir_y * data->ray.movespeed * data->ray.bord);
	c = (int)p->pos_y;
	if (!char_in_string(data->map.grid[c][l], "1"))
		p->pos_x += p->dir_y * data->ray.movespeed;
	l = (int)p->pos_x;
	c = (int)(p->pos_y - p->dir_x * data->ray.movespeed * data->ray.bord);
	if (!char_in_string(data->map.grid[c][l], "1"))
		p->pos_y -= p->dir_x * data->ray.movespeed;
	return (true);
}

bool	move_map_right(t_game *data)
{
	int			l;
	int			c;
	t_player	*p;

	p = &data->player;
	l = (int)(p->pos_x - p->dir_y * data->ray.movespeed * data->ray.bord);
	c = (int)p->pos_y;
	if (!char_in_string(data->map.grid[c][l], "1"))
		p->pos_x -= p->dir_y * data->ray.movespeed;
	l = (int)p->pos_x;
	c = (int)(p->pos_y + p->dir_x * data->ray.movespeed * data->ray.bord);
	if (!char_in_string(data->map.grid[c][l], "1"))
		p->pos_y += p->dir_x * data->ray.movespeed;
	return (true);
}

bool	rotate(t_game *data, int direction)
{
	t_player	*p;
	double		speed_rot;

	p = &data->player;
	speed_rot = direction * data->ray.rotspeed;
	p->olddir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(speed_rot) - p->dir_y * sin(speed_rot);
	p->dir_y = p->olddir_x * sin(speed_rot) + p->dir_y * cos(speed_rot);
	p->oldplane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(speed_rot) - p->plane_y * sin(speed_rot);
	p->plane_y = p->oldplane_x * sin(speed_rot) + p->plane_y * cos(speed_rot);
	return (true);
}
