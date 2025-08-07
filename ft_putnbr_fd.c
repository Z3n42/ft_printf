/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:55:39 by ingonzal          #+#    #+#             */
/*   Updated: 2021/07/27 21:21:24 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd, int *len)
{
	unsigned int	numb;

	if (n < 0)
	{
		(*len)++;
		numb = (unsigned int)(n * (-1));
		write(fd, "-", 1);
	}
	else
		numb = (unsigned int) n;
	if (numb > 9)
	{
		ft_putnbr_fd (numb / 10, fd, len);
		ft_putnbr_fd (numb % 10, fd, len);
	}
	else
	{
		(*len)++;
		ft_putchar_fd (numb + '0', fd);
	}
}
