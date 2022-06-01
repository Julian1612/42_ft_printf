/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:26:10 by aestraic          #+#    #+#             */
/*   Updated: 2022/06/01 10:39:28 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
///////////////////////////
# include <stdio.h>
///////////////////////////

int			ft_printf(const char *input_str, ...);
char		*ft_itoa(long n);
void		print_char(const char output_char);
int			write_string(const char *input_str, va_list arguments);
int			conversion_check(const char *input_str,
				int index, va_list arguments);
int			output_character(va_list arguments);
int			output_string(va_list arguments);
int			output_numbers(va_list arguments);
int			output_intiger(va_list arguments);
int			output_percent(void);
int			output_ptr_adr(va_list arguments);
void		print_ptr_address(unsigned long long decimal_nbr);
int			output_lowercase_hexa(va_list argument);
void		print_lowercase_hexa(unsigned int decimal_nbr);
int			output_uppercase_hexa(va_list arguments);
void		print_uppercase_hexa(unsigned int decimal_nbr);
int			output_unsigned_int(va_list arguments);
int			number_length_hexa(unsigned long long numb);
long		number_length(long numb);
static char	*get_string(long numb, char *str, long numb_len);

#endif
