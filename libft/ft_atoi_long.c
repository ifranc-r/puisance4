/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:39:12 by qmerlot           #+#    #+#             */
/*   Updated: 2016/02/24 19:04:05 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_sign(const char c)
{
	if (c == '-')
		return ('-');
	if (c == '+')
		return ('+');
	return ('0');
}

long		ft_atoi_long(const char *str)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (ft_sign(*str) == '-')
		sign = -1;
	if (ft_sign(*str) != '0')
		str++;
	if (ft_isdigit(*str) == 0)
		return (0);
	while (*str != '\0' && ft_isdigit(*str))
	{
		result = result * 10;
		result = result + (*str - '0');
		str++;
	}
	return (result * sign);
}
