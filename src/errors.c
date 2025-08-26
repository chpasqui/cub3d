/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:05:58 by Charlye           #+#    #+#             */
/*   Updated: 2025/08/26 14:07:04 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_map_error(t_map *map, char *msg)
{
	printf("Error\n%s\n", msg);
	free_map(map);
	exit(EXIT_FAILURE);
}

void	handle_error(t_game *data, char *msg)
{
	printf("Error\n%s\n", msg);
	clean_exit(data, EXIT_FAILURE);
}
