/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:18:26 by chpasqui          #+#    #+#             */
/*   Updated: 2025/09/04 16:34:04 by sydubois         ###   ########.fr       */
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

bool	char_in_string2(char a, char *b)
{
	printf("a = %c \n", a);
	while (*b != '\0')
	{
		if (*b == a)
			return (true);
		b++;
	}
	return (false);
}
