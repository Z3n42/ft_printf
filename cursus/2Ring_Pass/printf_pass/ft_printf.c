/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:55:56 by ingonzal          #+#    #+#             */
/*   Updated: 2021/09/21 19:05:15 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_puts(va_list ap, const char *format, int count)
{
	int	len;

	len = 0;
	if (format[count] == 'c')
		len += ft_putchar_fd(va_arg(ap, int), 1);
	if (format[count] == 's')
		len += ft_putstr_fd(va_arg(ap, char *), 1);
	if (format[count] == 'p')
	{
		len = 2;
		write(1, "0x", 2);
		ft_putnbr_p(va_arg(ap, uintptr_t), 1, &len);
	}
	if (format[count] == 'd' || format[count] == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1, &len);
	if (format[count] == 'u')
		ft_putnbr_long(va_arg(ap, unsigned int), 1, &len);
	if (format[count] == 'x')
		ft_putnbr_hex(va_arg(ap, unsigned int), 1, &len);
	if (format[count] == 'X')
		ft_putnbr_hexmay(va_arg(ap, unsigned int), 1, &len);
	if (format[count] == '%')
		len += ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	int			len;

	len = 0;
	va_start(ap, format);
	count = 0;
	while (format[count])
	{
		if (format[count] == '%')
		{
			count++;
			len += ft_puts(ap, format, count);
			count++;
		}
		else
		{
			ft_putchar_fd(format[count], 1);
			count++;
			len++;
		}
	}
	va_end(ap);
	return (len);
}

int	main(void)
{	
	char 			a;
	int 			b;
	char*	c = "deeq";

	a = 'a';
	b =	1050;
	ft_printf("mia: c%c, s%s, d%d, x%x, p%p\n", a, c, b, b, 20);
	printf("ori: c%c, s%s, d%d, x%x, p%p", a, c, b, b, 20);
}
