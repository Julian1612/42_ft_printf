/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_03.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:14:06 by jschneid          #+#    #+#             */
/*   Updated: 2022/05/30 11:21:38 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	long	len_numb;
	char	*str;
	char	*newstr;

	len_numb = numblen(n);
	str = malloc((len_numb + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	newstr = getstr(n, str, len_numb);
	return (newstr);
}

static long	numblen(int numb)
{
	int	i;

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

static char	*getstr(long numb, char *str, long len_numb)
{
	long	newnum;
	int		sign;

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
