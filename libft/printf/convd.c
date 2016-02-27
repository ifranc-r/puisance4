/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:34:02 by qmerlot           #+#    #+#             */
/*   Updated: 2016/02/08 16:00:13 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char static	*ft_preci_d(char *dstr, t_flags *flags)
{
	char	*str;
	int		diff;

	if (flags->disneg == 1)
		flags->preci += 1;
	diff = flags->preci - ft_strlen(dstr);
	str = ft_strnew(flags->preci);
	ft_memset(str, '0', flags->preci);
	if (flags->disneg == 1)
	{
		str[diff] = '0';
		str[0] = '-';
		dstr++;
	}
	while (str[diff] != '\0')
	{
		str[diff] = *dstr++;
		diff++;
	}
	return (str);
}

char static	*ft_sign_d(char *ptr, t_flags *flags, int diff)
{
	if (diff <= 0 || (diff > 0 && flags->neg == 1))
	{
		(flags->space == 1) ? ft_putchar_c(' ') : 0;
		(flags->plus == 1) ? ft_putchar_c('+') : 0;
		if ((flags->space == 1 || flags->plus == 1) && flags->neg == 1)
			ptr[ft_strlen(ptr) - 1] = '\0';
	}
	else if (flags->neg == 0)
	{
		if (flags->space == 1 && flags->zero == 0)
			ptr[diff - 1] = ' ';
		if (flags->space == 1 && flags->zero == 1)
			ptr[0] = ' ';
		if (flags->plus == 1 && flags->zero == 0)
			ptr[diff - 1] = '+';
		if (flags->plus == 1 && flags->zero == 1)
			ptr[0] = '+';
		if (flags->disneg == 1 && flags->zero == 1)
		{
			ptr[0] = '-';
			ptr[diff] = '0';
		}
	}
	return (ptr);
}

void static	ft_finalstr_d(char *ptr, t_flags *flags)
{
	char	*preci;
	char	*ret;
	size_t	len;
	int		diff;

	if (flags->disneg == 1)
		flags->preci += 1;
	diff = flags->preci - ft_strlen(ptr);
	preci = NULL;
	if (diff > 0 && (preci = ft_preci_d(ptr, flags)))
		ptr = preci;
	if (flags->preci == 0 && flags->isnull == 1)
		ptr[0] = '\0';
	len = ft_strlen(ptr);
	diff = flags->field - len;
	if (diff > 0)
		ret = ft_fdif(ptr, diff, flags);
	else
		ret = ft_strdup(ptr);
	ret = ft_sign_d(ret, flags, diff);
	ft_putstr_c(ret);
	if (ret)
		ft_strdel(&ret);
	if (preci)
		ft_strdel(&preci);
}

char static	ft_change_letter_d(char c, t_flags *flags)
{
	if (c == 'i')
		c = 'd';
	if (c == 'D')
	{
		c = 'd';
		flags->modifok = 1;
		flags->l = 1;
		flags->ll = 0;
		flags->h = 0;
		flags->hh = 0;
	}
	return (c);
}

void		ft_conversion_d(char c, t_flags *flags, va_list ap)
{
	char	*dstr;

	dstr = NULL;
	c = ft_change_letter_d(c, flags);
	if (flags->h == 1 || flags->hh == 1 || flags->modifok == 0)
		dstr = ft_itoa_ll(va_arg(ap, int), flags);
	else if (flags->l == 1)
		dstr = ft_itoa_ll(va_arg(ap, long), flags);
	else if (flags->ll == 1 || flags->j == 1 || flags->z == 1)
		dstr = ft_itoa_ll(va_arg(ap, long long), flags);
	if (dstr[0] == '-')
	{
		flags->disneg = 1;
		flags->space = 0;
		flags->plus = 0;
	}
	ft_finalstr_d(dstr, flags);
	if (dstr != NULL)
		ft_strdel(&dstr);
}
