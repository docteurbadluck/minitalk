/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:31:45 by ashobajo          #+#    #+#             */
/*   Updated: 2024/06/12 05:17:14 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putnumber(long n, int base);
int	ft_putnumber_caps(long n, int base);
int	print_format(char specifier, va_list ap);
int	ft_putunit_max(unsigned long num, int base);
int	ft_putpointer(void *pointer);
int	ft_putstring(char *str);

#endif
