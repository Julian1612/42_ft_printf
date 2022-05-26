/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:20:33 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/26 10:57:44 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
///////////Delet after finish/////////
#include <stdio.h>
//////////////////////////////////////

int		ft_printf(const char *input_str, ...);
int		count_output_len(const char *input_str);
int		conversion_check();
int		count_passed_args(const char *input_str);
char	creat_output_string(char str_output, int str_len);

//The actual function ft_printf
int ft_printf(const char *input_str, ...)
{
	int		str_len;
	char	*str_output;

	va_list arguments;
	va_start(arguments, input_str);
	str_output = creat_output_string(input_str);
	write_string();
	va_end(arguments);
	return (str_len);
}

// Gets the the complete length of the string wich will be the output
// including the length of the variables
int count_output_len(const char *input_str)
{
	int index;
	int char_counter;

	index = 0;
	char_counter = 0;
	while (input_str[index] != '\0')
	{
		if (input_str[index] == '%' && (input_str[index + 1] == 'c' || input_str[index + 1] == 's'
		|| input_str[index + 1] == 'p' || input_str[index + 1] == 'd' || input_str[index + 1] == 'i'
		|| input_str[index + 1] == 'u' || input_str[index + 1] == 'x' || input_str[index + 1] == 'X'
		|| input_str[index + 1] == '%'))
			char_counter += conversion_check(input_str, index);
		index++;
	}
	char_counter += (index - (2 * count_passed_args(input_str)));
	return (char_counter);
}

// Checks wich character is used after the %
// and returns the a value between 0 and 9
int conversion_check(const char *input_str, int index)
{
	if (input_str[index + 1] == 'c')
		return (1);
	else if (input_str[index + 1] == 's')
		return (2);
	else if (input_str[index + 1] == 'p')
		return (3);
	else if (input_str[index + 1] == 'd')
		return (4);
	else if (input_str[index + 1] == 'i')
		return (5);
	else if (input_str[index + 1] == 'u')
		return (6);
	else if (input_str[index + 1] == 'x')
		return (7);
	else if (input_str[index + 1] == 'X')
		return (8);
	else if (input_str[index + 1] == '%')
		return (1);
	else
		return (0);
}

//counts the number of passwd arguments to the variadic function
int count_passed_args(const char *input_str)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (input_str[i] != '\0')
	{
		if (input_str[i] == '%' && input_str[i + 1] != '%')
			counter++;
		i++;
	}
	return (counter);
}

//creats the string for the output and coverts the conversions to the actual value
char creat_output_string(char str_output, int str_len)
{

}

int main ()
{
	printf("////////////////Original////////////////\n");
	printf("output: ");
	int y = printf("hall%c", 'o');
	printf("\nchars: %i", y);
	printf("\n//////////////////My/////////////////\n");
	printf("output: ");
	int x = ft_printf("hall%c", 'o');
	printf("\nchars: %i\n", x);
	return (0);
}
