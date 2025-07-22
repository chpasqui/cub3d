/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:49:47 by chpasqui          #+#    #+#             */
/*   Updated: 2024/10/15 14:31:44 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	total_size;

	total_size = count * size;
	ptr = malloc (total_size);
	if (ptr != NULL)
	{
		ft_memset(ptr, 0, total_size);
	}
	return (ptr);
}

/*#include <stdio.h>

int	main(void)
{
	void	*ptr;
	size_t	count = 2;
	size_t	size = 4;
	size_t	i = 0;
	size_t	total_size = count * size;

	ptr = ft_calloc(count, size);
	if (ptr == NULL)
		return (1);
	printf("memory calloc :");
	while (i < total_size)
	{
		printf("%d", ((unsigned char *)ptr)[i]);
		i++;
	}
	printf("\n");
	free(ptr);
	return (0);
}
*/