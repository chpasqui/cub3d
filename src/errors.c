/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:05:58 by Charlye           #+#    #+#             */
/*   Updated: 2025/09/04 21:05:59 by sydubois         ###   ########.fr       */
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
