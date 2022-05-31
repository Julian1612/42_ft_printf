/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:09:46 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/31 11:54:44 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Gets the value from the argument and uses function 'put_char'
// to print it to the standart output
int	output_character(va_list arguments)
{
	int	character;

	character = va_arg(arguments, int);
	print_char(character);
	return (1);
}
