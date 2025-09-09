/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:32:29 by sydubois          #+#    #+#             */
/*   Updated: 2025/09/09 13:28:19 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	move_map_up2(t_game *data)
{
	int			l;
	int			c;
	t_player	*p;

	p = &data->player;
	l = (int)(p->pos_x + p->dir_x * data->ray.movespeed * data->ray.bord);
	c = (int)p->pos_y;
	if (!c_in_s(data->map.grid[c][l], "1"))
	{
		l = (int)p->pos_x;
		c = (int)(p->pos_y + p->dir_y * data->ray.movespeed * data->ray.bord);
		if (!c_in_s(data->map.grid[c][l], "1"))
		{
			p->pos_x += p->dir_x * data->ray.movespeed;
			p->pos_y += p->dir_y * data->ray.movespeed;
		}
	}
	return (true);
}

bool	move_map_down2(t_game *data)
{
	int			l;
	int			c;
	t_player	*p;

	p = &data->player;
	l = (int)(p->pos_x - p->dir_x * data->ray.movespeed * data->ray.bord);
	c = (int)p->pos_y;
	if (!c_in_s(data->map.grid[c][l], "1"))
	{
		l = (int)p->pos_x;
		c = (int)(p->pos_y - p->dir_y * data->ray.movespeed * data->ray.bord);
		if (!c_in_s(data->map.grid[c][l], "1"))
		{
			p->pos_x -= p->dir_x * data->ray.movespeed;
			p->pos_y -= p->dir_y * data->ray.movespeed;
		}
	}
	return (true);
}

bool	move_map_left2(t_game *data)
{
	int			l;
	int			c;
	t_player	*p;

	p = &data->player;
	l = (int)(p->pos_x + p->dir_y * data->ray.movespeed * data->ray.bord);
	c = (int)p->pos_y;
	if (!c_in_s(data->map.grid[c][l], "1"))
	{
		l = (int)p->pos_x;
		c = (int)(p->pos_y - p->dir_x * data->ray.movespeed * data->ray.bord);
		if (!c_in_s(data->map.grid[c][l], "1"))
		{
			p->pos_x += p->dir_y * data->ray.movespeed;
			p->pos_y -= p->dir_x * data->ray.movespeed;
		}
	}
	return (true);
}

bool	move_map_right2(t_game *data)
{
	int			l;
	int			c;
	t_player	*p;

	p = &data->player;
	l = (int)(p->pos_x - p->dir_y * data->ray.movespeed * data->ray.bord);
	c = (int)p->pos_y;
	if (!c_in_s(data->map.grid[c][l], "1"))
	{
		l = (int)p->pos_x;
		c = (int)(p->pos_y + p->dir_x * data->ray.movespeed * data->ray.bord);
		if (!c_in_s(data->map.grid[c][l], "1"))
		{
			p->pos_x -= p->dir_y * data->ray.movespeed;
			p->pos_y += p->dir_x * data->ray.movespeed;
		}
	}
	return (true);
}
