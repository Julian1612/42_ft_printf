/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:14:06 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/31 10:32:56 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Converts the given intiger number to a string
char	*ft_itoa(long n)
{
	long long	len_numb;
	char	*str;
	char	*newstr;

	len_numb = numblen(n);
	str = malloc((len_numb + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	newstr = getstr(n, str, len_numb);
	return (newstr);
}

// Gets the length of the given intiger number
long long	numblen(long numb)
{
	long long	i;

	i = 0;
	if (numb == 0 || numb < 0)
		i++;
	while (numb != 0)
	{
		numb /= 10;
		i++;
	}
	return (i);
}

// Converts the given long number to a string
static char	*getstr(long numb, char *str, long len_numb)
{
	long long	newnum;
	long		sign;

	newnum = 0;
	sign = 0;
	str[len_numb] = '\0';
	if (numb == 0)
		str[0] = '0';
	if (numb < 0)
	{
		numb *= -1;
		sign = 1;
	}
	while (len_numb > 0)
	{
		newnum = numb % 10;
		str[len_numb -1] = 48 + newnum;
		numb /= 10;
		len_numb--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
