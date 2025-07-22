/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:49:07 by chpasqui          #+#    #+#             */
/*   Updated: 2024/10/10 14:30:43 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/*#include <stdio.h>

int	main(void)
{
	char	b[] = "blabla";
	int	c;
	size_t	len;
	size_t	i;

	c = 'a';
	len = 2;
	i = 0;

	ft_memset(b, c, len);
	printf("memset : %s\n", ft_memset(b, c, len));
	return (0);
}*/