/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:10:24 by jschneid          #+#    #+#             */
/*   Updated: 2022/06/01 13:21:51 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Gets the value from the argument and itarrets through the string and prints
// every character with help of print_char
int	output_string(va_list arguments)
{
	int		index;
	char	*string;

	index = 0;
	string = va_arg(arguments, char *);
	if (string == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (string[index] != '\0')
	{
		print_char(string[index]);
		index++;
	}
	return (index);
}
