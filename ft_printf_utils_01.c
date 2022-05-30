/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:00:44 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/30 14:18:26 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Gets the value from the argument and coverts the intigr number to a string,
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

// Gives the 'print_char' function a '%' prints it and returns 2
int	output_percent(void)
{
	print_char('%');
	return (2);
}

// Gets the pointer adress and prints it with the 'decimal_to_hexadecimal'
int	output_ptr_adr(va_list arguments)
{
	int					length_address;
	unsigned long long	ptr;

	ptr = (unsigned long long) va_arg(arguments, void *);
	length_address = get_number_length(ptr);
	write(1, "0x", 2);
	print_ptr_address(ptr);
	return (length_address);
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

void	print_ptr_address(unsigned long long decimal_nbr)
{
	long long	new_value;

	new_value = decimal_nbr % 16 + 48;
	decimal_nbr /= 16;
	if (decimal_nbr > 0)
		print_ptr_address(decimal_nbr);
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
