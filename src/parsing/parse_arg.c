/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:57:53 by chpasqui          #+#    #+#             */
/*   Updated: 2025/08/18 20:03:05 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_file_extension(char *path, int len)
{
	int	i;

	i = len - 1;
	if (path[i] != 'b' || path[i - 1] != 'u' || path[i -2] != 'c'
		|| path[i - 3] != '.')
		return (false);
	return (true);
}

bool	parse_file(char *path, t_game *data)
{
	// lire le fichier
	//parse les identifiants 
	// extract la map
	// verifier la validite des textures
	// verifier la validite de la map
}

bool	parse_arg(char *path, t_game *data)
{
	int	len;
	int	fd;

	len = ft_strlen(path);
	if (len < 5)
		handle_error(data, INVALID_NAME);
	if (!check_file_extension(path, len))
		handle_error(data, BAD_EXTENSION);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		handle_error(data, CANOT_OPEN);
	close(fd);
	if (!parse_file(path, data))
		return (false);
	return (true);
}