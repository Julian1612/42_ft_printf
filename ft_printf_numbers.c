/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbersmbs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:09:56 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/30 16:22:48 by jschneid         ###   ########.fr       */
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
