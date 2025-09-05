/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_logo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:35:40 by Charlye           #+#    #+#             */
/*   Updated: 2025/09/05 15:32:59 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	render_logo(t_game *data)
{
	char	*img_logo;
	int		width;
	int		height;
	void	*logo;

	img_logo = "./src/rendering/cub3d_logo_30x30.xpm";
	width = 30;
	height = 30;
	if (access(img_logo, F_OK) != 0)
	{
		perror("fichire introuvable\n");
		return (false);
	}
	logo = mlx_xpm_file_to_image(data->mlx.mlx, img_logo, &width, &height);
	if (!logo)
	{
		printf("probleme logo %s et l = %p\n ", img_logo, logo);
		return (false);
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window, logo, 100, 0);
	return (true);
}
