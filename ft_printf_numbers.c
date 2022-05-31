/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:09:56 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/31 10:34:13 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Gets the value from the argument and coverts the intiger number to a string,
// then the function itarretes through the string
// and prints the characters with print_cahr
int	output_numbers(va_list arguments)
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

// Gets the value from the argument check if its positiv
// converts the number to a string and prints it to the standart output
// using 'print_char'
int	output_unsigned_int(va_list arguments)
{
	int		index;
	long	decimal_number;
	char	*string_number;

	index = 0;
	decimal_number = va_arg(arguments, int);
	if (decimal_number < 0)
	{
		decimal_number = 4294967296 + (decimal_number);
	}
	string_number = ft_itoa(decimal_number);
	while (string_number[index] != '\0')
	{
		print_char(string_number[index]);
		index++;
	}
	return (index);
}
