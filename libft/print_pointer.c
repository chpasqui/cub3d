/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:27:39 by chpasqui          #+#    #+#             */
/*   Updated: 2025/08/26 13:58:52 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_pointer(unsigned long n);

int	ft_print_pointer(void *ptr)
{
	unsigned long	un_ptr;
	int				count;

	un_ptr = (unsigned long) ptr;
	count = 0;
	count += ft_putstr("0x");
	if (ptr == 0)
		count += ft_putchar('0');
	else
		count += convert_pointer(un_ptr);
	return (count);
}

static int	convert_pointer(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += convert_pointer(n / 16);
		count += convert_pointer(n % 16);
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
