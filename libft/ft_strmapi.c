/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:37:22 by chpasqui          #+#    #+#             */
/*   Updated: 2024/10/10 13:20:48 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_s;

	i = 0;
	new_s = malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (new_s == NULL)
		return (NULL);
	while (s[i])
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	new_s [i] = '\0';
	return (new_s);
}

/*#include <stdio.h>

int	main(void)
{
	char s[] = "test";
	char	*str;

	str = ft_strmapi(s, ft_toupper_n);
	if (str == NULL)
		return (1);
	printf("%s\n", str);
	free (str);
	return (0);
}

	char	ft_toupper_n(unsigned int i, char c)
{
	if (i == 1 && (c >= 'a' && c <= 'z'))
		return (c - 32);
	return (c);	
}*/