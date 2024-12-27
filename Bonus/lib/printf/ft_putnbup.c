/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unputnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamisoa <rmamisoa@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:10:13 by rmamisoa          #+#    #+#             */
/*   Updated: 2024/03/14 16:10:15 by rmamisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbup(long n, int base)
{
	char	*sign;
	int		c;

	sign = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putnbup(-n, base) + 1);
	}
	if (n < base)
	{
		return (ft_putchar(sign[n]));
	}
	else
	{
		c = ft_putnbup(n / base, base);
		return (c + ft_putnbup(n % base, base));
	}
	return (c);
}
