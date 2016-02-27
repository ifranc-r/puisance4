/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 17:51:42 by qmerlot           #+#    #+#             */
/*   Updated: 2016/02/10 18:57:38 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void static	ft_wchar_cpy(wchar_t *dst, wchar_t *src)
{
	int		x;

	x = 0;
	while (src[x] != '\0')
	{
		dst[x] = src[x];
		x++;
	}
}

void static	ft_fdif_w(wchar_t *ptr, int diff, t_flags *flags, char c)
{
	wchar_t		fill;

	fill = ' ';
	if (flags->zero == 1)
		fill = '0';
	if (flags->neg == 0)
	{
		while (diff--)
			ft_putcharw_c(fill);
	}
	if (c == 'S' && flags->preci == -1)
		ft_putstrw_c(ptr);
	else if (c != 'C')
		ft_putstrwlen_c(ptr, flags->preci);
	if (c == 'C')
		ft_putcharw_c(ptr[0]);
	if (flags->neg == 1)
	{
		while (diff--)
			ft_putcharw_c(fill);
	}
}

void static	ft_finalstr_w(wchar_t *ptr, t_flags *flags, char c)
{
	int			len;
	int			diff;
	wchar_t		nullstr[7];

	ft_wchar_cpy(nullstr, L"(null)");
	if (ptr == NULL)
		ptr = nullstr;
	len = ft_strlenw(ptr);
	if (flags->preci < len && flags->preci != -1 && c == 'S')
		len = flags->preci;
	diff = flags->field - len;
	if (diff > 0)
		ft_fdif_w(ptr, diff, flags, c);
	else if (diff <= 0 && c != 'C')
		ft_putstrw_cc(ptr, flags);
	else if (diff <= 0 && c == 'C')
		ft_putcharw_c(ptr[0]);
}

void		ft_conversion_w(char c, t_flags *flags, va_list ap)
{
	wchar_t		w[2];
	wchar_t		*ptr;

	w[1] = L'\0';
	if (c == 'C')
	{
		w[0] = va_arg(ap, wchar_t);
		ptr = w;
	}
	if (c == 'S')
		ptr = va_arg(ap, wchar_t *);
	ft_finalstr_w(ptr, flags, c);
}
