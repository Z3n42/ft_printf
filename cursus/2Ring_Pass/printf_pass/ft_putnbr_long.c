/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:54:18 by ingonzal          #+#    #+#             */
/*   Updated: 2021/07/27 14:37:48 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putnbr_long(long int n, int fd, int *len)
{
	if (n > 9)
	{
		ft_putnbr_long(n / 10, fd, len);
		ft_putnbr_long(n % 10, fd, len);
	}
	else
	{
		(*len)++;
		ft_putchar_fd(n + '0', fd);
	}
}
