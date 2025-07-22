/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:50:12 by chpasqui          #+#    #+#             */
/*   Updated: 2024/10/15 14:27:06 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*p_dst;
	unsigned const char	*p_src;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned const char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (p_src < p_dst)
	{
		while (len-- > 0)
			p_dst[len] = p_src[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			p_dst[i] = p_src[i];
			i++;
		}
	}
	return (dst);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[20] = "Geeksfor";
	size_t	len = strlen(src) + 1;

	ft_memmove(src + 5, src, len);
    printf("Après ft_memmove: %s\n", src); 
	return (0);
}*/