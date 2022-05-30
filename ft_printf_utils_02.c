/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_02.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:01:49 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/30 14:18:44 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_lowercase_hexa(va_list arguments)
{
	int					length_address;
	int					ptr;

	ptr = va_arg(arguments, int);
	length_address = get_number_length(ptr);
	print_lowercase_hexa(ptr);
	return (length_address);
}

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

int	output_uppercase_hexa(va_list arguments)
{
	int					length_address;
	int					ptr;

	ptr = va_arg(arguments, int);
	length_address = get_number_length(ptr);
	print_uppercase_hexa(ptr);
	return (length_address);
}

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

int	output_unsigned_int(va_list arguments)
{
	int		index;
	int		decimal_number;
	char	*string_number;

	index = 0;
	decimal_number = va_arg(arguments, int);
	if (decimal_number < 0)
	{
		write(1, "4294967295", 10);
		return (10);
	}
	string_number = ft_itoa(decimal_number);
	while (string_number[index] != '\0')
	{
		print_char(string_number[index]);
		index++;
	}
	return (index);
}
