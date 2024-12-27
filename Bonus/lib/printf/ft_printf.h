/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamisoa <rmamisoa@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 09:12:50 by rmamisoa          #+#    #+#             */
/*   Updated: 2024/03/16 09:12:52 by rmamisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	print_format(char specifier, va_list ap);
int	ft_printf(const char *format, ...);
int	ft_print_pointer(unsigned long n, int base);
int	ft_putchar(char c);
int	ft_putnbr(long n, int base);
int	ft_putnbup(long n, int base);
int	ft_putstr(char *str);

#endif
