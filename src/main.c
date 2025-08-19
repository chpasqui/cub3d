/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:33:21 by chpasqui          #+#    #+#             */
/*   Updated: 2025/08/19 16:43:37 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc != 2)
		handle_error(&data, WRONG_ARGS);
	ft_bzero(&data, sizeof(t_game));
	if (!parse_arg(argv[1], &data.map))
		handle_error(&data, PARSE_FAIL);
	init_mlx(&data);
	init_game(&data);
	render_loop(&data); // RAYCASTING
	clean_exit(&data, EXIT_SUCCESS);
	return (0);
}