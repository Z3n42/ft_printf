/* ************************************************************************** */
                                                                          
/*                                                        :::      :::::::: */  
/*   mainprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+ */    
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+ */       
/*                                                +#+#+#+#+#+   +#+ */          
/*   Created: 2021/07/17 14:55:52 by ingonzal          #+#    #+# */            
/*   Updated: 2021/07/27 21:10:26 by ingonzal         ###   ########.fr       */
                                                                          
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	/* char a[] = "Hola q tal"; */
	int ft;
	int or;
	/* a = 2; */

	ft = ft_printf("FTiginal :%p %p\n ", 0, 0);
	or = printf("Original :%p %p\n ", 0, 0);
	/* p8 */
	/* ft = ft_printf("FTiginal : %p %p ", ULONG_MAX, -ULONG_MAX); */
	/* or = printf("Original : %p %p ", ULONG_MAX, -ULONG_MAX); */
	/* p9 */
	/* ft = ft_printf("FTiginal : %p %p ", 0, 0); */
	/* or = printf("Original %p %p ", 0, 0); */
	/* d29 */
	/* ft = ft_printf("FTiginal :%d", 123); */
	/* or = printf("Original :%d", 123); */
	/* i29 */
	/* ft = ft_printf("FTiginal :%i %i %i %i %i %i %i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42); */
	/* or = printf("Original :%i %i %i %i %i %i %i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42); */
	/* u29 */
	/* ft = ft_printf("FTiginal :%u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42); */
	/* or = printf("Original :%u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42); */
	/* x29 */
	/* ft = ft_printf("FTiginal :%x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42); */
	/* or = printf("Original :%x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42); */
	/* X29 */
	/* ft = ft_printf("FTiginal :%X %X %X %X %X %X %X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42); */
	/* or = printf("Original :%X %X %X %X %X %X %X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42); */
	/* mix */	
	/* ft = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0); */
	/* or = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0); */
	printf("FT int :%d\n", ft);
	printf("Or :%d", or);
}
