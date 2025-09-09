/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:33:21 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/09 10:38:18 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_game *data)
{
	clean_exit(data, EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	data;

	ft_bzero(&data.map, sizeof(t_game));
	if (argc != 2)
		handle_error(&data, WRONG_ARGS);
	init_map(&data.map);
	if (!parse_arg(argv[1], &data.map))
		handle_error(&data, PARSE_FAIL);
	init_game(&data);
	if (!init_mlx(&data))
		handle_error(&data, MLX_ERROR);
	if (!init_all_textures(&data))
		handle_error(&data, TEX_FAIL);
	// Looking at main function
	render_game(&data);
	mlx_hook(data.mlx.window, 17, 0, close_window, &data);
	mlx_mouse_hook(data.mlx.window, mouse_hook, &data);
	mlx_hook(data.mlx.window, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx.window, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx.mlx, key_hook, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
