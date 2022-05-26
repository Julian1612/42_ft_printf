/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:56:49 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/26 19:10:42 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
///////////Delet after finish/////////
#include <stdio.h>
//////////////////////////////////////

int		ft_printf(const char *input_str, ...);
int		write_string(const char *input_str, va_list arguments);
void	print_char(const char output_char);
int		conversion_check(const char *input_str, int index, va_list arguments);
int		output_character(va_list arguments);
int		output_string(va_list arguments);
int		output_decimal(va_list arguments);
int		output_intiger(va_list arguments);
int		output_percent();
// 'ft_printf' main function
int	ft_printf(const char *input_str, ...)
{
	int printed_chars;

	printed_chars = 0;
	va_list arguments;
	va_start(arguments, input_str);
	printed_chars = write_string(input_str, arguments);
	va_end(arguments);
	return (printed_chars);
}

// Iterrats through the given string and prints the single charcters.
// When a '%' character occurs the function starts function 'conversion_check'
int write_string(const char *input_str, va_list arguments)
{
	int index;
	int char_counter;

	index = 0;
	char_counter = 0;
	while (input_str[index] != '\0')
	{
		if (input_str[index] == '%')
		{
			char_counter += conversion_check(input_str, index, arguments);
			index++;
		}
		else
			print_char(input_str[index]);
		if (input_str[index] != '%' && input_str[index - 1] != '%')
			char_counter++;
		index++;
	}
	return (char_counter);
}

// Writes the given string to the output
void print_char(const char output_char)
{
	write(1, &output_char, 1);
}

// Checks wich character is used after the %
// and returns the a value between 0 and 9
int conversion_check(const char *input_str, int index, va_list arguments)
{
	if (input_str[index + 1] == 'c')
		return (output_character(arguments));
	else if (input_str[index + 1] == 's')
		return (output_string(arguments));
/*  else if (input_str[index + 1] == 'p')
		output_d(arguments); */
	else if (input_str[index + 1] == 'd')
		return (output_decimal(arguments));
	else if (input_str[index + 1] == 'i')
		return (output_decimal(arguments));
/*	else if (input_str[index + 1] == 'u')
		return (6);
	else if (input_str[index + 1] == 'x')
		return (7);
	else if (input_str[index + 1] == 'X')
		return (8); */
	else if (input_str[index + 1] == '%')
		return (output_percent());

	else
		return (0);
}

// Gets the value from the argument and starts function 'put_char'
int output_character(va_list arguments)
{
	int character;

	character = va_arg(arguments, int);
	print_char(character);
	return (1);
}

// Gets the value from the argument and itarrets through the string and prints
// every character with help of print_char
int output_string(va_list arguments)
{
	int index;
	char *string;

	index = 0;
	string =  va_arg(arguments, char *);
	while (string[index] != '\0')
	{
		print_char(string[index]);
		index++;
	}
	return (index);
}

// Gets the value from the argument and coverts the intigr number to a string,
// then the function itarretes through the string and prints the characters with print_cahr
int output_numbers(va_list arguments)
{
	int		index;
	int		decimal_number;
	char	*string_number;

	index = 0;
	decimal_number = va_arg(arguments, int);
	string_number = ft_itoa(decimal_number);
	while (string_number[index] != '\0')
	{
		print_char(string_number[index]);
		index++;
	}
	return (index);
}

int output_percent()
{
	print_char('%');
	return (2);
}

int main ()
{
	printf("////////////////Original////////////////\n");
	printf("output: ");
	int y = printf("hallo %s %i %% %% %% %% %% %d", "julian", 565, 711);
	printf("\nchars: %i", y);
	printf("\n///////////////////My///////////////////\n");
	printf("output: ");
	fflush(stdout);
	int x = ft_printf("hallo %s %i %% %% %% %% %% %d", "julian", 565, 711);
	printf("\nchars: %i", x);
	return (0);
}
