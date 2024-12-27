/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamisoa <rmamisoa@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:36:39 by rmamisoa          #+#    #+#             */
/*   Updated: 2024/03/14 11:36:46 by rmamisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	c;

	c = 0;
	if (specifier == 'c')
		c = ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		c = ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		c = ft_putnbr(va_arg(ap, int), 10);
	else if (specifier == 'u')
		c = ft_putnbr(va_arg(ap, unsigned int), 10);
	else if (specifier == 'x')
		c = ft_putnbr(va_arg(ap, unsigned int), 16);
	else if (specifier == 'X')
		c = ft_putnbup(va_arg(ap, unsigned int), 16);
	else if (specifier == '%')
		c = ft_putchar('%');
	else if (specifier == 'p')
		c = ft_print_pointer(va_arg(ap, unsigned long), 16);
	else
		c = write(1, &specifier, 1);
	return (c);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		c;
	int		i;

	c = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			c += print_format(format[i], ap);
		}
		else
		{
			c += write (1, &format[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (c);
}
