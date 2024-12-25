/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamisoa <rmamisoa@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:41:15 by rmamisoa          #+#    #+#             */
/*   Updated: 2024/03/14 15:41:17 by rmamisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n, int base)
{
	char	*sign;
	int		c;

	sign = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr(-n, base) + 1);
	}
	if (n < base)
	{
		return (ft_putchar(sign[n]));
	}
	else
	{
		c = ft_putnbr(n / base, base);
		return (c + ft_putnbr(n % base, base));
	}
	return (c);
}
