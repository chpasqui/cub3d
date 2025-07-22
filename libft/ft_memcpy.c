/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:50:02 by chpasqui          #+#    #+#             */
/*   Updated: 2024/10/15 14:27:00 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (dst);
	if (dst == NULL && src == NULL)
		return (0);
	if (src > dst || (dst + n < src))
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	else
		ft_memmove(dst, src, n);
	return (dst);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dst[] = "old";
	char	src[] = "new";
	size_t	n = sizeof(src);
	
	printf("my function : %s\n", (char *)ft_memcpy(dst, src, n));
	printf("libc function : %s\n", (char *)memcpy(dst, src, n));
	return (0);
}*/