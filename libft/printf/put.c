/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:29:50 by qmerlot           #+#    #+#             */
/*   Updated: 2016/02/07 20:25:53 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_c(int n)
{
	static int	count = 0;

	if (n == 0)
		count = 0;
	if (n == 1)
		count++;
	return (count);
}

void	ft_putchar_c(int c)
{
	ft_putchar(c);
	ft_count_c(1);
}

void	ft_putstr_c(char *s)
{
	int		n;

	n = 0;
	while (s[n] != '\0')
	{
		ft_putchar_c(s[n]);
		n++;
	}
}

void	ft_putstrlen_c(char *s, int len)
{
	int		n;

	n = 0;
	while (s[n] != '\0' && len--)
	{
		ft_putchar_c(s[n]);
		n++;
	}
}

void	ft_putstr_cc(char *s, int len)
{
	int		n;

	n = 0;
	while (len--)
	{
		ft_putchar_c(s[n]);
		n++;
	}
}
