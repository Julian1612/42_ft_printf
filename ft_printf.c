/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:56:49 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/26 13:27:06 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
///////////Delet after finish/////////
#include <stdio.h>
//////////////////////////////////////

int		ft_printf(const char *input_str, ...);
void	write_string(const char *input_str, va_list arguments);
void	put_char(const char output_char);
void	conversion_check(const char *input_str, int index, va_list arguments);
void	output_c(va_list arguments);

//ft_printf main function
int	ft_printf(const char *input_str, ...)
{
	int printed_chars;

	printed_chars = 0;
	va_list arguments;
	va_start(arguments, input_str);
	/* printed_chars = */ write_string(input_str, arguments);

	va_end(arguments);
	return (printed_chars);
}

//iterrats through the given string and prints the single charcters
//when a '%' character occurs the function stars function 'conversion_check'
void write_string(const char *input_str, va_list arguments)
{
	int index;

	index = 0;
	while (input_str[index] != '\0')
	{
		if (input_str[index] == '%')
		{
			conversion_check(input_str, index, arguments);
			index++;
		}
		else
			put_char(input_str[index]);
		index++;
	}
}

//writes the given string to the output
void put_char(const char output_char)
{
	write(1, &output_char, 1);
}

// Checks wich character is used after the %
// and returns the a value between 0 and 9
void conversion_check(const char *input_str, int index, va_list arguments)
{
	if (input_str[index + 1] == 'c')
		output_c(arguments);
	else if (input_str[index + 1] == 's')
		output_s(arguments);
/* 	else if (input_str[index + 1] == 'p')
		return (3);
	else if (input_str[index + 1] == 'd')
		return (4);
	else if (input_str[index + 1] == 'i')
		return (5);
	else if (input_str[index + 1] == 'u')
		return (6);
	else if (input_str[index + 1] == 'x')
		return (7);
	else if (input_str[index + 1] == 'X')
		return (8);
	else if (input_str[index + 1] == '%')
		return (1);
	else
		return (0); */
}

//Gets the vaulue from the argument and starts function 'put_char'
void output_c(va_list arguments)
{
	int c;

	c = va_arg(arguments, int);
	put_char(c);
}

void output_s(va_list arguments)
{
	int index;

	index = 0;
	while (arguments[index] != '\0')
	{

		index++;
	}
}

int main ()
{
	printf("////////////////Original////////////////\n");
	printf("output: ");
	int y = printf("hall%c", 'o');
	printf("\nchars: %i", y);
	printf("\n///////////////////My///////////////////\n");
	printf("output: ");
	fflush(stdout);
	int x = ft_printf("hall%c", 'o');
	return (0);
}
