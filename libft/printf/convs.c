/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:22:54 by qmerlot           #+#    #+#             */
/*   Updated: 2016/02/10 18:11:27 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char		*ft_fdif(char *ptr, int diff, t_flags *flags)
{
	char	*ret;
	int		n;

	n = 0;
	if ((ret = ft_strnew(flags->field)) != NULL)
	{
		if (flags->zero == 1)
			ft_memset(ret, '0', flags->field);
		else
			ft_memset(ret, ' ', flags->field);
		if (flags->neg == 1 && flags->c == 1)
			ret[0] = ptr[0];
		else if (flags->neg == 1)
			ft_strncpy(ret, ptr, ft_strlen(ptr));
		else
		{
			while (*ptr != '\0')
				ret[diff++] = *ptr++;
			if (flags->c == 1)
				ret[diff] = ptr[0];
		}
	}
	flags->strlen = flags->field;
	return (ret);
}

void static	ft_finalstr_s(char *ptr, t_flags *flags, char c)
{
	char	*preci;
	char	*ret;
	size_t	len;
	int		diff;

	preci = NULL;
	if (flags->preci >= 0 && c == 's'
			&& (preci = ft_strndup(ptr, flags->preci)))
		ptr = preci;
	len = ft_strlen(ptr);
	(c == 'c') ? len = 1 : 0;
	diff = flags->field - len;
	if (diff > 0)
		ret = ft_fdif(ptr, diff, flags);
	else
	{
		ret = ft_strdup(ptr);
		flags->strlen = len;
	}
	ft_putstr_cc(ret, flags->strlen);
	if (ret)
		ft_strdel(&ret);
	if (preci)
		ft_strdel(&preci);
}

int	static	ft_isconvs(char c, t_flags *flags)
{
	if ((c == 'c' && flags->l == 0) || (c == 's' && flags->l == 0) || c == '%')
		return (1);
	return (0);
}

void		ft_conversion_s(char c, t_flags *flags, va_list ap)
{
	char	tmp[2];
	char	*ptr;
	char	nullstr[7];

	ft_strcpy(nullstr, "(null)");
	tmp[1] = '\0';
	(c == 'c' && flags->l == 1) ? c = 'C' : 0;
	(c == 's' && flags->l == 1) ? c = 'S' : 0;
	if (c == 'c' && flags->l == 0)
		tmp[0] = va_arg(ap, int);
	if ((c != 's' && c != 'S' && c != 'c' && c != 'C') && (tmp[0] = c))
	{
		flags->l = 0;
		c = 'c';
	}
	if ((c == 'c' && flags->l == 0) && (ptr = tmp))
		flags->c = 1;
	if (c == 's' && flags->l == 0)
		ptr = va_arg(ap, char *);
	if (ptr == NULL)
		ptr = nullstr;
	if (c == 'C' || c == 'S')
		ft_conversion_w(c, flags, ap);
	else if (ft_isconvs(c, flags) == 1)
		ft_finalstr_s(ptr, flags, c);
}
