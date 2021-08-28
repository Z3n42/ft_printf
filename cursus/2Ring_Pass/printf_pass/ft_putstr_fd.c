/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:09:25 by ingonzal          #+#    #+#             */
/*   Updated: 2021/07/27 19:42:42 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (s == NULL)
	{
		write (fd, "(null)", 6);
		return (6);
	}
	while (s[count] != '\0')
	{
		write (fd, &s[count], 1);
		count++;
	}
	return (count);
}
