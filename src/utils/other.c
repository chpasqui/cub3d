/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:18:26 by chpasqui          #+#    #+#             */
/*   Updated: 2025/08/29 11:19:16 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_space(char *line)
{
	int	s;

	s = 0;
	while (line[s] == ' ')
		s++;
	return (s);
}

bool	char_in_string(char a, char *b)
{
	while (*b != '\0')
	{
		if (*b == a)
			return (true);
		b++;
	}
	return (false);
}
