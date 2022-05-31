/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_%p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:10:15 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/31 09:21:38 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Gets the pointer adress,
// gets the length of the adress with 'get_number_length'
// and prints it with the 'prints_ptr_address'
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

// prints the given number as a lowercase hexadecimal number
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
