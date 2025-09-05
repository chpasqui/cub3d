/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:33:06 by Charlye           #+#    #+#             */
/*   Updated: 2025/09/05 14:58:26 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// setup la vision (position, direction, plane)
// 

bool	render_loop(t_game *data)
{
	render_ray(data);
	render_minimap(data);
//	render_logo(data);
	return (true);
}
