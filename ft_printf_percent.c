/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_%%.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:08:32 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/31 09:26:16 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Gives the 'print_char' function a '%' prints it to the
// standart output and returns 2
int	output_percent(void)
{
	print_char('%');
	return (2);
}
