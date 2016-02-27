/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:09:04 by qmerlot           #+#    #+#             */
/*   Updated: 2016/02/07 16:20:38 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

char static	ft_get_base(int value, int upcase)
{
	char	basetab[16];

	if (upcase == 0)
		ft_strcpy(basetab, "0123456789abcdef");
	else
		ft_strcpy(basetab, "0123456789ABCDEF");
	return (basetab[value]);
}

char static	*ft_strrevdup(char *str)
{
	char	tmp[50];
	int		n;
	int		x;

	x = 0;
	n = ft_strlen(str);
	n--;
	while (n >= 0)
		tmp[x++] = str[n--];
	tmp[x] = '\0';
	return (ft_strdup(tmp));
}

int static	ft_is_neg(long long value)
{
	if (value < 0)
		return (1);
	return (0);
}

char		*ft_itoa_ll(long long value, t_flags *flags)
{
	char	tmp[50];
	int		n;
	int		isneg;

	(flags->h == 1) ? value = (short)value : 0;
	(flags->hh == 1) ? value = (signed char)value : 0;
	if (value == 0)
	{
		flags->isnull = 1;
		return (ft_strdup("0"));
	}
	isneg = ft_is_neg(value);
	n = 0;
	while (value)
	{
		tmp[n++] = ft_abs(value % 10) + '0';
		value /= 10;
	}
	if (isneg == 1)
	{
		tmp[n] = '-';
		n++;
	}
	tmp[n] = '\0';
	return (ft_strrevdup(tmp));
}

char		*ft_itoa_u_base(unsigned long long value, int base, int upcase,
							t_flags *flags)
{
	char	tmp[50];
	int		n;

	(flags->h == 1) ? value = (unsigned short)value : 0;
	(flags->hh == 1) ? value = (unsigned char)value : 0;
	if (value == 0)
	{
		flags->isnull = 1;
		return (ft_strdup("0"));
	}
	n = 0;
	while (value)
	{
		tmp[n] = ft_get_base(ft_abs(value % base), upcase);
		value /= base;
		n++;
	}
	tmp[n] = '\0';
	return (ft_strrevdup(tmp));
}
