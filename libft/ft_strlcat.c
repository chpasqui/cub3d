/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:49:18 by chpasqui          #+#    #+#             */
/*   Updated: 2024/10/13 13:58:56 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (dstsize < dst_len)
		return ((dstsize + src_len));
	while (src[i] && ((dst_len + i) < (dstsize - 1)))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return ((dst_len + src_len));
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dst[] = "test";
	char	*src;
	size_t	dstsize;

	dstsize = 10; 
	src = "cool";

	printf("%zu\n", ft_strlcat(dst, src, dstsize));
	//printf("%zu\n", strlcat(dst, src, dstsize));
	return (0);
}*/