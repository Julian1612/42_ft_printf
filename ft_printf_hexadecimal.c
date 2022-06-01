/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:10:38 by jschneid          #+#    #+#             */
/*   Updated: 2022/06/01 11:09:42 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Gets the value from the argument, checks the length
// of the number, prints out the lowercase hexadecimal number
// and returns the number of digits wich are printed
int	output_lowercase_hexa(va_list arguments)
{
	int					length_address;
	unsigned int		number;

	number = va_arg(arguments, unsigned int);
	length_address = number_length_hexa(number);
	print_lowercase_hexa(number);
	return (length_address);
}

// Converts the given number to lowercase hexadecimal number
// and use 'print_char' to print the digits
void	print_lowercase_hexa(unsigned int decimal_nbr)
{
	unsigned int	new_value;

	new_value = decimal_nbr % 16 + 48;
	decimal_nbr /= 16;
	if (decimal_nbr > 0)
		print_lowercase_hexa(decimal_nbr);
	if (new_value == 58)
		new_value = 'a';
	else if (new_value == 59)
		new_value = 'b';
	else if (new_value == 60)
		new_value = 'c';
	else if (new_value == 61)
		new_value = 'd';
	else if (new_value == 62)
		new_value = 'e';
	else if (new_value == 63)
		new_value = 'f';
	print_char(new_value);
}

// Gets the value from the argument, checks the length
// of the number, prints out the lowercase hexadecimal number
// and returns the number of digits wich are printed
int	output_uppercase_hexa(va_list arguments)
{
	int					length_address;
	unsigned int		number;

	number = va_arg(arguments, unsigned long long);
	length_address = number_length_hexa(number);
	print_uppercase_hexa(number);
	return (length_address);
}

// Converts the given number to uppercase hexadecimal number
// and use 'print_char' to print the digits
void	print_uppercase_hexa(unsigned int decimal_nbr)
{
	unsigned int	new_value;

	new_value = decimal_nbr % 16 + 48;
	decimal_nbr /= 16;
	if (decimal_nbr > 0)
		print_uppercase_hexa(decimal_nbr);
	if (new_value == 58)
		new_value = 'A';
	else if (new_value == 59)
		new_value = 'B';
	else if (new_value == 60)
		new_value = 'C';
	else if (new_value == 61)
		new_value = 'D';
	else if (new_value == 62)
		new_value = 'E';
	else if (new_value == 63)
		new_value = 'F';
	print_char(new_value);
}
