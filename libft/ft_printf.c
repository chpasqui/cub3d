/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Charlye <Charlye@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:23:18 by chpasqui          #+#    #+#             */
/*   Updated: 2025/08/19 14:27:20 by Charlye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* handle_format: handle the conversion specifier in the format string */
static int	handle_format(const char *format, va_list args, int i)
{
	int	count;

	count = 0;
	if (format[i] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format[i] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format[i] == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (format[i] == 'x')
		count += ft_print_hex_lower(va_arg(args, unsigned int));
	else if (format[i] == 'X')
		count += ft_print_hex_upper(va_arg(args, unsigned int));
	else if (format[i] == 'p')
		count += ft_print_pointer(va_arg(args, void *));
	else if (format[i] == '%')
		count += ft_putchar('%');
	return (count);
}

/* ft_printf: implementation of the printf function */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += handle_format(format, args, i);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
