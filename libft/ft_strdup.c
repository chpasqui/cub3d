/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:49:15 by chpasqui          #+#    #+#             */
/*   Updated: 2024/11/11 17:47:36 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char		*ptr;
	int			i;

	ptr = (char *)malloc(ft_strlen(s1) + 1);
	if (ptr != NULL)
	{
		i = 0;
		while (s1[i])
		{
			ptr[i] = s1[i];
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}

/*#include <stdio.h>
int	main(void)
{
	char s1[] = "hello";
	printf("%s\n", ft_strdup(s1));
	return (0);
}*/