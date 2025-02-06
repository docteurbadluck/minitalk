/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:28:58 by ashobajo          #+#    #+#             */
/*   Updated: 2024/06/12 05:10:24 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar (va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstring (va_arg (ap, char *));
	else if (specifier == 'i' || specifier == 'd')
		count += ft_putnumber ((((long)va_arg (ap, int))), 10);
	else if (specifier == 'u')
		count += ft_putunit_max (((va_arg (ap, unsigned int))), 10);
	else if (specifier == 'x')
		count += ft_putnumber (va_arg (ap, unsigned int), 16);
	else if (specifier == 'X')
		count += ft_putnumber_caps (va_arg (ap, unsigned int), 16);
	else if (specifier == 'p')
		count += ft_putpointer(va_arg (ap, void *));
	else
		count += write (1, &specifier, 1);
	return (count);
}
