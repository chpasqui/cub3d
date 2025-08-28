/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:17:02 by Charlye           #+#    #+#             */
/*   Updated: 2025/08/28 13:26:41 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*left_trim(char *str)
{
	while (*str == ' ')
		str++;
	return(str);
}

void	right_trim(char *str, int len)
{
	while (len > 0 && str[len - 1] == ' ')
		len--;
	str[len] == '\0';
}