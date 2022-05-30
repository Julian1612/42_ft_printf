/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_00.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:35:17 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/30 16:23:54 by jschneid         ###   ########.fr       */
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

int	get_number_length(long long ptr_address)
{
	int	length;

	length = 0;
	while (ptr_address > 0)
	{
		ptr_address /= 10;
		if (ptr_address > 0)
			length ++;
	}
	return (length);
}

void	print_char(const char output_char)
{
	write(1, &output_char, 1);
}
