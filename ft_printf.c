/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:56:49 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/30 16:03:03 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
///////////Delet after finish/////////
#include <stdio.h>
//////////////////////////////////////

// 'ft_printf' main function
int	ft_printf(const char *input_str, ...)
{
	int		printed_chars;
	va_list	arguments;

	printed_chars = 0;
	va_start(arguments, input_str);
	printed_chars = write_string(input_str, arguments);
	va_end(arguments);
	return (printed_chars);
}

int	main (void)
{
	int *x;
	char *y;
	long *z;

	printf("//////////////////// Original ////////////////////\n");
	int a = printf("This is a test");
	printf("\nCount: %i", a);
	printf("\n");
	printf("%c %c %c %c", 'a', ' ', '1', '\n');
	printf("\n");
	printf("%s %s %s", "string", "s", "   \t\n  ");
	printf("\n");
	printf("%p %p %p", x, y, z);
	printf("\n");
	printf("%d %d %d", 2147483647, -2147483647, 0);
	printf("\n");
	printf("%u %u %u", 1, -2, 0);
	printf("\n");
	printf("%x %x %x %x %x", 2147483647, -2147483647, 0, 1, 42);
	printf("\n");
	printf("%X %X %X %X %X", 2147483647, -2147483647, 0, 1, 42);
	printf("\n");
	printf("%% %%% %%%% %");
	printf("\n/////////////////////// My ///////////////////////\n");
	int b = ft_printf("This is a test");
	ft_printf("\nCount: %i", b);
	ft_printf("\n");
	ft_printf("%c %c %c %c", 'a', ' ', '1', '\n');
	ft_printf("\n");
	ft_printf("%s %s %s", "string", "s", "   \t\n  ");
	ft_printf("\n");
	ft_printf("%p %p %p", x, y ,z);
	ft_printf("\n");
	ft_printf("%d %d %d", 2147483647, -2147483647, 0);
	ft_printf("\n");
	ft_printf("%u %u %u", 1, -2, 0);
	ft_printf("\n");
	ft_printf("%x %x %x %x %x", 2147483647, -2147483647, 0, 1, 42);
	ft_printf("\n");
	ft_printf("%X %X %X %X %X", 2147483647, -2147483647, 0, 1, 42);
	ft_printf("\n");
	ft_printf("%% %%% %%%% %");
	printf("\n//////////////////////////////////////////////////");
	return (0);
}
