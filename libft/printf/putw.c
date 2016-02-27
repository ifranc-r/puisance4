/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:09:14 by qmerlot           #+#    #+#             */
/*   Updated: 2016/02/10 18:28:08 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_count_n(unsigned int c, int plus)
{
	int		n;

	n = 0;
	if (c < 0x80)
		n = 1;
	else if (c < 0x800)
		n = 2;
	else if (c < 0x10000)
		n = 3;
	else if (c < 0x200000)
		n = 4;
	if (plus == 1)
	{
		while (n--)
			ft_count_c(1);
	}
	return (n);
}

void		ft_putcharw_c(unsigned int c)
{
	if (c < 0x80)
		ft_putchar(c);
	else if (c < 0x800)
	{
		ft_putchar(0xC0 | (c >> 6));
		ft_putchar(0x80 | (c & 0x3F));
	}
	else if (c < 0x10000)
	{
		ft_putchar(0xE0 | (c >> 12));
		ft_putchar(0x80 | ((c >> 6) & 0x3F));
		ft_putchar(0x80 | (c & 0x3F));
	}
	else if (c < 0x200000)
	{
		ft_putchar(0xF0 | (c >> 18));
		ft_putchar(0x80 | ((c >> 12) & 0x3F));
		ft_putchar(0x80 | ((c >> 6) & 0x3F));
		ft_putchar(0x80 | (c & 0x3F));
	}
	ft_count_n(c, 1);
}

void		ft_putstrw_c(wchar_t *s)
{
	while (*s != '\0')
		ft_putcharw_c(*s++);
}

void		ft_putstrwlen_c(wchar_t *s, int len)
{
	while (*s != '\0' && len--)
		ft_putcharw_c(*s++);
}

size_t		ft_strlenw(wchar_t *s)
{
	size_t	n;

	n = 0;
	while (*s != '\0')
	{
		n += ft_count_n(*s, 0);
		s++;
	}
	return (n);
}
