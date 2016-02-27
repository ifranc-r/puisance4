/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:56:05 by qmerlot           #+#    #+#             */
/*   Updated: 2016/02/10 17:38:38 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char static	ft_change_letter_b(char c, t_flags *flags)
{
	if (c == 'U' || c == 'O' || c == 'B')
	{
		flags->modifok = 1;
		flags->l = 1;
		flags->ll = 0;
		flags->h = 0;
		flags->hh = 0;
	}
	if (c == 'O')
		c = 'o';
	if (c == 'U')
		c = 'u';
	if (c == 'B')
		c = 'b';
	return (c);
}

char static	*ft_preci_b(char *bstr, int size)
{
	char	*str;
	int		diff;

	diff = size - ft_strlen(bstr);
	str = ft_strnew(size);
	ft_memset(str, '0', size);
	while (str[diff] != '\0')
	{
		str[diff] = *bstr++;
		diff++;
	}
	return (str);
}

int static	ft_check_preci_b(char *ptr, t_flags *flags, char c)
{
	int		diff;
	int		len;

	if (flags->isnull == 1 && flags->preci == 0)
		ptr[0] = '\0';
	len = ft_strlen(ptr);
	diff = flags->preci - len;
	if (!(flags->p == 1 && flags->preci == 0)
		&& (diff < 1 && flags->hash == 1 && c == 'o'
		&& (!(flags->isnull == 1 && flags->hash == 1 && flags->preci == -1))))
	{
		flags->preci = len + 1;
		diff = flags->preci - len;
	}
	return (diff);
}

void static	ft_finalstr_b(char *ptr, t_flags *flags, char c)
{
	char	*preci;
	char	*ret;
	int		len;
	int		diff;

	diff = ft_check_preci_b(ptr, flags, c);
	preci = NULL;
	if (diff > 0 && (preci = ft_preci_b(ptr, flags->preci)))
		ptr = preci;
	len = ft_strlen(ptr);
	diff = flags->field - len;
	if (diff > 0)
		ret = ft_fdif(ptr, diff, flags);
	else
		ret = ft_strdup(ptr);
	if (flags->p == 1 || !(flags->isnull == 1 && flags->preci == 0))
		ret = ft_hexa(ret, flags, diff, c);
	ft_putstr_c(ret);
	if (ret)
		ft_strdel(&ret);
	if (preci)
		ft_strdel(&preci);
}

void		ft_conversion_b(char c, t_flags *flags, va_list ap)
{
	char	*bstr;
	int		upc;
	int		base;

	bstr = NULL;
	upc = 0;
	(c == 'X') ? upc = 1 : 0;
	c = ft_change_letter_b(c, flags);
	base = ft_get_base_b(c);
	if (c == 'p')
	{
		bstr = ft_itoa_u_base(va_arg(ap, unsigned long long), 16, upc, flags);
		c = 'x';
		flags->p = 1;
	}
	else if (flags->h == 1 || flags->hh == 1 || flags->modifok == 0)
		bstr = ft_itoa_u_base(va_arg(ap, unsigned int), base, upc, flags);
	else if (flags->l == 1)
		bstr = ft_itoa_u_base(va_arg(ap, unsigned long), base, upc, flags);
	else if (flags->ll == 1 || flags->j == 1 || flags->z == 1)
		bstr = ft_itoa_u_base(va_arg(ap, unsigned long long), base, upc, flags);
	ft_finalstr_b(bstr, flags, c);
	if (bstr != NULL)
		ft_strdel(&bstr);
}
