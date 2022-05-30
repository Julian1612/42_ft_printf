/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:26:10 by aestraic          #+#    #+#             */
/*   Updated: 2022/05/30 14:20:12 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
///////////////////////////
///////////////////////////

char		*ft_itoa(int n);
void		print_char(const char output_char);
int			write_string(const char *input_str, va_list arguments);
int			conversion_check(const char *input_str, int index, va_list arguments);
int			output_character(va_list arguments);
int			output_string(va_list arguments);
int			output_numbers(va_list arguments);
int			output_intiger(va_list arguments);
int			output_percent(void);
int			output_ptr_adr(va_list arguments);
void		print_ptr_address(unsigned long long decimal_nbr);
int			get_number_length(long long ptr_address);
int			output_lowercase_hexa(va_list argument);
void		print_lowercase_hexa(unsigned long long decimal_nbr);
int			output_uppercase_hexa(va_list arguments);
void		print_uppercase_hexa(unsigned long long decimal_nbr);
int			output_unsigned_int(va_list arguments);
char		*ft_itoa(int n);
static long	numblen(int numb);
static char	*getstr(long numb, char *str, long numb_len);

#endif
