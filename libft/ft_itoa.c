/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:07:20 by qmerlot           #+#    #+#             */
/*   Updated: 2015/12/03 17:31:16 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_intlen(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	len = ft_intlen(n);
	sign = ft_sign(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if ((str = (char *)malloc(sizeof(char) * (len + sign + 1))))
	{
		str = str + len + sign;
		*str = '\0';
		if (n < 0)
			n = -n;
		if (!n)
			*--str = '0';
		while (n != 0)
		{
			*--str = (n % 10) + '0';
			n /= 10;
		}
		if (sign)
			*--str = '-';
	}
	return (str);
}
