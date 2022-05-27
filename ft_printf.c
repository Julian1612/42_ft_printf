/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:56:49 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/27 15:58:38 by jschneid         ###   ########.fr       */
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
int		output_numbers(va_list arguments);
int		output_intiger(va_list arguments);
int		output_percent(void);
int		output_ptr_adr(va_list arguments);
int	decimal_to_hexadecimal(unsigned long long decimal_nbr, int counter);

// 'ft_printf' main function
int	ft_printf(const char *input_str, ...)
{
	int		printed_chars;
	va_list	arguments;

	printed_chars = 0;
	va_start(arguments, input_str);
	printed_chars = write_string(input_str, arguments);
	va_end(arguments);
	return (printed_chars);
}

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
/*	else if (input_str[index + 1] == 'u')
		return (6);
	else if (input_str[index + 1] == 'x')
		return (7);
	else if (input_str[index + 1] == 'X')
		return (8); */
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

// Gets the value from the argument and coverts the intigr number to a string,
// then the function itarretes through the string and prints the characters with print_cahr
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
int	output_percent()
{
	print_char('%');
	return (2);
}

// Gets the pointer adress and prints it with the 'decimal_to_hexadecimal'
// CAUTION Function does not return the lenth how many characters the address has !!! needs to be fixed
int	output_ptr_adr(va_list arguments)
{
	int					index;
	unsigned long long	ptr;

	index = 0;
	ptr = (unsigned long long) va_arg(arguments, void *);
	write(1, "0x", 2);
	return (decimal_to_hexadecimal(ptr, index));
}

// !!!!!!!!!!!!!!!!!!!
// Function printed zwar die adresse korrekt aber durch die recurssion kann nicht gezahlt werden wie viel characters die addresse hat :( needs to fixed
int	decimal_to_hexadecimal(unsigned long long decimal_nbr, int counter)
{
	long long	new_value;

	new_value = decimal_nbr % 16 + 48;
	decimal_nbr /= 16;
	if (decimal_nbr > 0)
		decimal_to_hexadecimal(decimal_nbr, counter);
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
	return (counter);
}

int	main ()
{
	int	*ptr;
	int	x;
	int	y;

	printf("////////////////Original////////////////\n");
	printf("output: ");
	y = printf("%p", ptr);
	printf("\nchars: %i", y);
	printf("\n///////////////////My///////////////////\n");
	printf("output: ");
	fflush(stdout);
	x = ft_printf("%p", ptr);
	printf("\nchars: %i", x);
	return (0);
}
