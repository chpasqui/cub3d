/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:04:45 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/09 14:09:00 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_game *data)
{
	clean_exit(data, EXIT_SUCCESS);
	return (0);
}

int	clean_exit(t_game *data, int code)
{
	free_game(data);
	exit(code);
}
