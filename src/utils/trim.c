/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:17:02 by Charlye           #+#    #+#             */
/*   Updated: 2025/09/04 21:06:38 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*left_trim(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

void	right_trim(char *str, int len)
{
	while (len > 0 && str[len - 1] == ' ')
		len--;
	str[len] = '\0';
}

char	*trim_all_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			str++;
		i++;
	}
	return (str);
}
