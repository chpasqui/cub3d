/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:49:11 by chpasqui          #+#    #+#             */
/*   Updated: 2024/10/10 14:36:11 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	c;
	const char *s;
	
	c = 'o';
	s = "hello30";

	printf("pointer : %s\n", ft_strchr(s, c));
	printf("pointer vrai: %s\n", strchr(s, c));
	return (0);
}*/