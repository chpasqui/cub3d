/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:56:43 by chpasqui          #+#    #+#             */
/*   Updated: 2024/10/21 14:05:18 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	absolute_value(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static int	nb_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		nb;
	char	*str;

	nb = nb_digits(n);
	str = malloc(sizeof(char) * (nb + 1));
	if (str == NULL)
		return (NULL);
	str[nb--] = '\0';
	if (n == 0)
		str[nb] = '0';
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		str[nb--] = absolute_value(n % 10) + '0';
		n /= 10;
	}
	return (str);
}

/*#include <stdio.h>

int	main(void)
{
	int		n;
	char	*str;
	size_t	i;

	i = 0;
	n = -2147483648;
	str = ft_itoa(n);
	if (str == NULL)
		return (0);
	printf("string : ");
	while (str[i])
	{
		printf("%c", str[i]);
		i++;
	}
	printf("\n");
	free(str);
	return (0);
}*/
