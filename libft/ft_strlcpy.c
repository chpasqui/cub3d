/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:45:16 by chpasqui          #+#    #+#             */
/*   Updated: 2024/10/10 15:09:34 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*#include <stdio.h>

int	main(void)
{
	char	dest[100];
	char	*src;
	size_t	dstsize;

	dstsize = 0;
	src = "cool";

	ft_strlcpy(dest, src, dstsize);
	printf("original string: %zu\n", ft_strlcpy(dest, src, dstsize));
	printf("%s\n", dest);
	return (0);
}*/
