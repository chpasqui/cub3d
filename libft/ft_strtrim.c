/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:24:31 by chpasqui          #+#    #+#             */
/*   Updated: 2024/10/13 16:10:32 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim_s;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_strrchr(set, s1[j - 1]))
		j--;
	len = j - i;
	trim_s = ft_substr(s1, i, len);
	return (trim_s);
}

/*#include <stdio.h>

int	main(void)
{
	char const s1[] = "helllo";
	char const s2[] = "he";

	printf("new string : %s\n", ft_strtrim(s1, s2));
	return (0);
}*/
