/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:48:22 by qmerlot           #+#    #+#             */
/*   Updated: 2016/02/01 18:47:10 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_check_field(const char *format, t_flags *flags)
{
	if (ft_isdigit(*format))
		flags->field = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	return (format);
}

const char	*ft_check_preci(const char *format, t_flags *flags)
{
	if (*format == '.')
	{
		flags->preci = 0;
		format++;
		if (ft_isdigit(*format))
			flags->preci = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
	}
	return (format);
}

void static	ft_check_double_letter(const char *format, t_flags *flags)
{
	if (*format == 'l')
	{
		if (*(format + 1) == 'l')
			flags->ll = 1;
		else
			flags->l = 1;
	}
	if (*format == 'h')
	{
		if (*(format + 1) == 'h')
			flags->hh = 1;
		else
			flags->h = 1;
	}
}

const char	*ft_check_modif(const char *format, t_flags *flags)
{
	if (flags->modifok != 1)
	{
		if (*format == 'j' || *format == 'z'
				|| *format == 'l' || *format == 'h')
			flags->modifok = 1;
		if (*format == 'j')
			flags->j = 1;
		if (*format == 'z')
			flags->z = 1;
		if (*format == 'l' || *format == 'h')
			ft_check_double_letter(format, flags);
	}
	while (*format == 'l' || *format == 'h' || *format == 'j' || *format == 'z')
		format++;
	return (format);
}
