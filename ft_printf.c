/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:56:49 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/31 11:09:31 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
///////////Delet after finish/////////
#include <stdio.h>
//////////////////////////////////////

// The printf utility formats and prints its arguments, after the first,
// under control of the format.  The format is a character string which
// contains three types of objects: plain characters, which are simply copied to
// standard output, character escape sequences which are converted and copied
// to the standard output and format specifications,
// each of which causes printing of the next successive argument.
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
	int		*x;
	char	*y;
	long	*z;
	int		a;
	int		b;

	printf("//////////////////// Original ////////////////////\n");
	printf("only string :");
	a = printf("This is a test");
	printf("\nCount: %i", a);
	printf("\nc :");
	printf("%c %c %c %c", 'a', ' ', '1', '\n');
	printf("\ns :");
	printf("%s %s %s %s", "string", "s", "   \t\n  ", "3311109");
	printf("\np :");
	printf("%p %p %p", x, y, z);
	printf("\nd :");
	printf("%d %d %d", 2147483647, -2147483647, 0);
	printf("\nu :");
	printf("%u %u %u %u %u %u %u %u %u %u %u %u %u", 0, -1, -2, -3, 2147483647, -2147483647, 429496, -429496, 10, -42, 100000, -0, 2);
	printf("\nx :");
	printf("%x %x %x %x %x", 2147483647, -2147483647, 0, 1, 42);
	printf("\nX :");
	printf("%X %X %X %X %X", 2147483647, -2147483647, 0, 1, 42);
	printf("\n%% :");
	printf("%% %%% %%%% %");
	printf("\n%% :");
	printf("\nAll :");
	printf("%c %s %p %d %u %x %X %% :", 'c', "string", x, -42, 42, 420, 420);
	printf("\n/////////////////////// My ///////////////////////\n");
	ft_printf("only string :");
	b = ft_printf("This is a test");
	ft_printf("\nCount: %i", b);
	ft_printf("\nc :");
	ft_printf("%c %c %c %c", 'a', ' ', '1', '\n');
	ft_printf("\ns :");
	ft_printf("%s %s %s %s", "string", "s", "   \t\n  ", "3311109");
	ft_printf("\np :");
	ft_printf("%p %p %p", x, y ,z);
	ft_printf("\nd :");
	ft_printf("%d %d %d", 2147483647, -2147483647, 0);
	ft_printf("\nu :");
	ft_printf("%u %u %u %u %u %u %u %u %u %u %u %u %u", 0, -1, -2, -3, 2147483647, -2147483647, 429496, -429496, 10, -42, 100000, -0, 2);
	ft_printf("\nx :");
	ft_printf("%x %x %x %x %x", 2147483647, -2147483647, 0, 1, 42);
	ft_printf("\nX :");
	ft_printf("%X %X %X %X %X", 2147483647, -2147483647, 0, 1, 42);
	ft_printf("\n%% :");
	ft_printf("%% %%% %%%% %");
	printf("%c %s %p %d %u %x %X %%", 'c', "string", x, -42, 42, 420, 420);
	printf("\n//////////////////////////////////////////////////");
	return (0);
}
