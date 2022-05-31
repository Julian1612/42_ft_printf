/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_%x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:10:38 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/31 09:15:17 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Gets the value from the argument, checks the length
// of the number, prints out the lowercase hexadecimal number
// and returns the number of digits wich are printed
int	output_lowercase_hexa(va_list arguments)
{
	int					length_address;
	int					ptr;

	ptr = va_arg(arguments, int);
	length_address = get_number_length(ptr);
	print_lowercase_hexa(ptr);
	return (length_address);
}

// Converts the given number to lowercase hexadecimal number
// and use 'print_char' to print the digits
void	print_lowercase_hexa(unsigned long long decimal_nbr)
{
	long long	new_value;

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
	int					ptr;

	ptr = va_arg(arguments, int);
	length_address = get_number_length(ptr);
	print_uppercase_hexa(ptr);
	return (length_address);
}

// Converts the given number to uppercase hexadecimal number
// and use 'print_char' to print the digits
void	print_uppercase_hexa(unsigned long long decimal_nbr)
{
	long long	new_value;

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
