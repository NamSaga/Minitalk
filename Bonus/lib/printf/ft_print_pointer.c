/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamisoa <rmamisoa@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:58:16 by rmamisoa          #+#    #+#             */
/*   Updated: 2024/03/16 08:58:19 by rmamisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long n, int base)
{
	char	*sign;
	int		result;

	result = 0;
	sign = "0123456789abcdef";
	if (n == 0)
	{
		result = write (1, "(nil)", 5);
		return (result);
	}
	if (n < 16)
	{
		result = ft_putstr("0x");
		result += ft_putchar(sign[n % 16]);
	}
	else
	{
		result = ft_putstr("0x");
		result += ft_putnbr(n / base, base);
		result += ft_putnbr(n % base, base);
	}
	return (result);
}
