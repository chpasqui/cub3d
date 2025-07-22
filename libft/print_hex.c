/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:29:28 by Charlye           #+#    #+#             */
/*   Updated: 2024/12/06 15:13:58 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex_lower(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_print_hex_lower(n / 16);
		count += ft_print_hex_lower(n % 16);
	}
	else
	{
		if (n < 10)
			count += ft_putchar(n + '0');
		else
			count += ft_putchar(n - 10 + 'a');
	}
	return (count);
}

int	ft_print_hex_upper(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_print_hex_upper(n / 16);
		count += ft_print_hex_upper(n % 16);
	}
	else
	{
		if (n < 10)
			count += ft_putchar(n + '0');
		else
			count += ft_putchar(n - 10 + 'A');
	}
	return (count);
}
