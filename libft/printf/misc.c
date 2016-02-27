/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:57:27 by qmerlot           #+#    #+#             */
/*   Updated: 2016/02/10 18:38:58 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_abs(int i)
{
	if (i < 0)
		i = -i;
	return (i);
}

int		ft_get_base_b(char c)
{
	int		base;

	base = 10;
	if (c == 'x' || c == 'X')
		base = 16;
	if (c == 'o')
		base = 8;
	if (c == 'b')
		base = 2;
	return (base);
}

char	*ft_hexa(char *ptr, t_flags *flags, int diff, char c)
{
	if (((c == 'x' || c == 'X') && flags->hash == 1
			&& !(ft_strlen(ptr) == 1 && ptr[0] == '0')) || flags->p == 1)
	{
		if (diff <= 0 || flags->neg == 1)
		{
			ft_putchar_c('0');
			ft_putchar_c(c);
			if (diff == 1)
				ptr[ft_strlen(ptr) - 1] = '\0';
			else if (diff >= 2)
				ptr[ft_strlen(ptr) - 2] = '\0';
		}
		else if (diff > 1 && flags->neg == 0 && flags->zero == 0)
		{
			ptr[diff - 1] = c;
			ptr[diff - 2] = '0';
		}
		else if (diff > 1 && flags->zero == 1)
			ptr[1] = c;
	}
	return (ptr);
}

void	ft_putstrw_cc(wchar_t *s, t_flags *flags)
{
	int		n;

	n = 0;
	if (flags->preci == -1)
	{
		while (s[n] != '\0')
		{
			ft_putcharw_c(s[n]);
			n++;
		}
	}
	else
	{
		while (flags->preci--)
		{
			ft_putcharw_c(s[n]);
			n++;
		}
	}
}
