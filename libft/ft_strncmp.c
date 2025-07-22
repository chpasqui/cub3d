/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:49:23 by chpasqui          #+#    #+#             */
/*   Updated: 2024/10/13 14:51:00 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((s1[i] || (s2[i])) && i < n))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*s1;
	const char	*s2;
	size_t	n;

	s1 = "sad1";
	s2 = "sad2";
	n = 3;

	printf("difference : %d\n", ft_strncmp(s1, s2, n));
	printf("vrai fonction : %d\n", strncmp(s1, s2, n));
	return (0);
}*/