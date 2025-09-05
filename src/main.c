/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:33:21 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/05 15:58:01 by Charlye          ###   ########.fr       */
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

	init_map(&data.map);
	if (argc != 2)
		handle_error(&data, WRONG_ARGS);
	if (!parse_arg(argv[1], &data.map))
		handle_error(&data, PARSE_FAIL);
	init_value(&data);
	init_mlx(&data);
	// init_game(&data);
	render_game(&data);
	mlx_hook(data.mlx.window, 17, 0, close_window, &data);
	mlx_mouse_hook(data.mlx.window, mouse_hook, &data);
//	mlx_key_hook(data.mlx.window, key_hook, &data);
	mlx_hook(data.mlx.window, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx.window, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx.mlx, key_hook, &data);
	mlx_loop(data.mlx.mlx);
	//clean_exit(&data, EXIT_SUCCESS);
	return (0);
}
