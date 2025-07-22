/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:43:16 by chpasqui          #+#    #+#             */
/*   Updated: 2024/10/10 13:47:08 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*#include <stdio.h>

void	ft_toupper_n(unsigned int i, char *c)
{
	if (i == 1 && (*c >= 'a' && *c <= 'z'))
		*c = *c - 32;
}

int	main(void)
{
	char s[] = "test";

	ft_striteri(s, ft_toupper_n);
	printf("%s\n", s);
	return (0);
}*/