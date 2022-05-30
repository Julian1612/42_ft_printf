/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:56:49 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/30 10:13:01 by jschneid         ###   ########.fr       */
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
void	print_ptr_address(unsigned long long decimal_nbr);
int		get_number_length(long long ptr_address);
int		output_lowercase_hexa(va_list argument);
void	print_lowercase_hexa(unsigned long long decimal_nbr);
int		output_uppercase_hexa(va_list arguments);
void	print_uppercase_hexa(unsigned long long decimal_nbr);

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
		return (6);*/
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
	int					length_address;
	unsigned long long	ptr;

	ptr = (unsigned long long) va_arg(arguments, void *);
	length_address = get_number_length(ptr);
	write(1, "0x", 2);
	print_ptr_address(ptr);
	return (length_address);
}

int get_number_length(long long ptr_address)
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

// !!!!!!!!!!!!!!!!!!!
// Function printed zwar die adresse korrekt aber durch die recurssion kann nicht gezahlt werden wie viel characters die addresse hat :( needs to fixed
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

int	output_lowercase_hexa(va_list arguments)
{
	int					length_address;
	unsigned long long	ptr;

	ptr = (unsigned long long) va_arg(arguments, void *);
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
	unsigned long long	ptr;

	ptr = (unsigned long long) va_arg(arguments, void *);
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

int	main ()
{
	int	*ptr;
	int	x;
	int	y;

	printf("////////////////Original////////////////\n");
	printf("output: ");
	y = printf("%X %x", 1299993, 4444444);
	printf("\nchars: %i", y);
	printf("\n///////////////////My///////////////////\n");
	printf("output: ");
	fflush(stdout);
	x = ft_printf("%X %x", 1299993, 4444444);
	printf("\nchars: %i", x);
	return (0);
}
