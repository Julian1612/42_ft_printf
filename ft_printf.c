/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:56:49 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/31 16:26:46 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
///////////Delet after finish/////////
#include <stdio.h>
#include <limits.h>
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
	int		c;
	int		d;

	printf("//////////////////// Original ////////////////////\n");
/* 	printf("only string :");
	a = printf("This is a test");
	printf("\nCount: %i", a);
	printf("\nc :");
	printf("% c %  c %c %c", 'a', ' ', '1', '\n');
	printf("\ns :");
	printf("%s %s %s %s", "string", "s", "   \t\n  ", "3311109");
	printf("\np :");
	a = printf("%p %p %p", -1, 2, 3);
	printf("\n%d", a);
	printf("\nd :");
	printf("%d %d %d", 2147483647, -2147483647, 0);
	printf("\nu :");
	printf("%u %u %u %u %u %u %u %u %u %u %u %u %u", 0, -1, -2,
	 -3, 2147483647, -2147483647, 429496, -429496, 10, -42, 100000, -0, 2);
 */	printf("\nx :");
	a = printf("%x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nlength: %d", a);
	printf("\nX :");
	b = printf("%x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nlength: %d", b);
/* 	printf("\n%% :");
	printf("% % % % %%");
	printf("\nAll :");
	printf("%c %s %p %d %u %x %X %% :", 'c', "string", x, -42, 42, 420, 420);
 */	printf("\n/////////////////////// My ///////////////////////\n");
/* 	ft_printf("only string :");
	b = ft_printf("This is a test");
	ft_printf("\nCount: %i", b);
	ft_printf("\nc :");
	ft_printf("%c %c %c %c", 'a', ' ', '1', '\n');
	ft_printf("\ns :");
	ft_printf("%s %s %s %s", "string", "s", "   \t\n  ", "3311109");
	ft_printf("\np :");
	b = ft_printf("%p %p %p", -1, 2, 3);
	printf("\n%d", b);
	ft_printf("\nd :");
	ft_printf("%d %d %d", 2147483647, -2147483647, 0);
	ft_printf("\nu :");
	ft_printf("%u %u %u %u %u %u %u %u %u %u %u %u %u", 0, -1, -2, -3, 2147483647, -2147483647, 429496, -429496, 10, -42, 100000, -0, 2);
 */	ft_printf("\nx :");
	c = ft_printf("%x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nlength: %d", c);
	ft_printf("\nX :");
	d = ft_printf("%X %X %X %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nlength: %d", d);
/* 	ft_printf("\n%% :");
	ft_printf("%% %%% %%%% %%%%% %%%%%%");
	ft_printf("\nAll :");
	printf("%c %s %p %d %u %x %X %%", 'c', "string", x, -42, 42, 420, 420);
 */	printf("\n//////////////////////////////////////////////////");
	return (0);
}

