/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_00.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:35:17 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/30 14:18:07 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Iterrats through the given string and prints the single charcters.
// When a '%' character occurs the function starts function 'conversion_check'
int	write_string(const char *input_str, va_list arguments)
{
	int		index;
	int		char_counter;

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
void	print_char(const char output_char)
{
	write(1, &output_char, 1);
}

// Checks wich character is used after the %
// and returns the a value between 0 and 9
int	conversion_check(const char *input_str, int index, va_list arguments)
{
	if (input_str[index + 1] == 'c')
		return (output_character(arguments));
	else if (input_str[index + 1] == 's')
		return (output_string(arguments));
	else if (input_str[index + 1] == 'p')
		return (output_ptr_adr(arguments));
	else if (input_str[index + 1] == 'd')
		return (output_numbers(arguments));
	else if (input_str[index + 1] == 'i')
		return (output_numbers(arguments));
	else if (input_str[index + 1] == 'u')
		return (output_unsigned_int(arguments));
	else if (input_str[index + 1] == 'x')
		return (output_lowercase_hexa(arguments));
	else if (input_str[index + 1] == 'X')
		return (output_uppercase_hexa(arguments));
	else if (input_str[index + 1] == '%')
		return (output_percent());
	return (0);
}

// Gets the value from the argument and starts function 'put_char'
int	output_character(va_list arguments)
{
	int	character;

	character = va_arg(arguments, int);
	print_char(character);
	return (1);
}

// Gets the value from the argument and itarrets through the string and prints
// every character with help of print_char
int	output_string(va_list arguments)
{
	int		index;
	char	*string;

	index = 0;
	string = va_arg(arguments, char *);
	while (string[index] != '\0')
	{
		print_char(string[index]);
		index++;
	}
	return (index);
}
