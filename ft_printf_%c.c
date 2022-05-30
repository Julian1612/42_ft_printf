/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_%c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:09:46 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/30 16:16:11 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Gets the value from the argument and starts function 'put_char'
int	output_character(va_list arguments)
{
	int	character;

	character = va_arg(arguments, int);
	print_char(character);
	return (1);
}
