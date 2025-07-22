/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:05:51 by chpasqui          #+#    #+#             */
/*   Updated: 2024/10/13 15:37:28 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	dst = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

	/*#include <stdio.h>

	int	main(void)
	{
		char const s1[] = "hey";
		char const s2[] = " boy";
		char	*dst;

		dst = ft_strjoin(s1, s2);
		if (dst == NULL)
			return (1);
		printf("new string : %s\n", ft_strjoin(s1, s2));
		free (dst);
		return (0);
	}*/