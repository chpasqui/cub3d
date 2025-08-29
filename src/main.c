/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:33:21 by chpasqui          #+#    #+#             */
/*   Updated: 2025/08/29 11:15:01 by sydubois         ###   ########.fr       */
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

	ft_bzero(&data, sizeof(t_game));
	if (argc != 2)
		handle_error(&data, WRONG_ARGS);
	if (!parse_arg(argv[1], &data.map))
		handle_error(&data, PARSE_FAIL);
	init_value(&data);
	init_mlx(&data);
	// init_game(&data);
	render_loop(&data); // RAYCASTING
	mlx_hook(data.mlx.window, 17, 0, close_window, &data);
	mlx_mouse_hook(data.mlx.window, mouse_hook, &data);
	mlx_key_hook(data.mlx.window, key_hook, &data);

	mlx_loop(data.mlx.mlx);
	clean_exit(&data, EXIT_SUCCESS);
	return (0);
}
