/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_%c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:09:46 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/31 09:25:32 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Gets the value from the argument and uses function 'put_char'
// to print it to yhe standart output
int	output_character(va_list arguments)
{
	int	character;

	character = va_arg(arguments, int);
	print_char(character);
	return (1);
}
