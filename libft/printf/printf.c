/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:49:17 by qmerlot           #+#    #+#             */
/*   Updated: 2016/02/10 19:30:24 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	static	ft_is_prefix(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+' || c == '.'
		|| ft_isdigit(c) == 1 || c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

void		ft_do_conversion(char c, t_flags *flags, va_list ap)
{
	if ((c == 'c' || c == 's' || c == 'C' || c == 'S') || c == '%')
		ft_conversion_s(c, flags, ap);
	else if (c == 'd' || c == 'i' || c == 'D')
	{
		flags->dec = 1;
		if (flags->zero == 1 && flags->preci >= 0)
			flags->zero = 0;
		ft_conversion_d(c, flags, ap);
	}
	else if (c == 'o' || c == 'O' || c == 'x' || c == 'X' || c == 'u'
			|| c == 'U' || c == 'p' || c == 'b' || c == 'B')
	{
		if (flags->zero == 1 && flags->preci >= 0)
			flags->zero = 0;
		if (c == 'p')
			flags->hash = 1;
		ft_conversion_b(c, flags, ap);
	}
	else
		ft_conversion_s(c, flags, ap);
}

const char	*ft_check_conversion(const char *format, va_list ap)
{
	t_flags		flags;

	ft_bzero(&flags, sizeof(flags));
	flags.preci = -1;
	while (ft_is_prefix(*format) == 1)
	{
		format = ft_check_flags(format, &flags);
		format = ft_check_field(format, &flags);
		format = ft_check_preci(format, &flags);
		format = ft_check_modif(format, &flags);
	}
	ft_do_conversion(*format, &flags, ap);
	return (format);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			format = ft_check_conversion(format, ap);
		}
		else
			ft_putchar_c(*format);
		format++;
	}
	va_end(ap);
	len = ft_count_c(2);
	ft_count_c(0);
	return (len);
}
