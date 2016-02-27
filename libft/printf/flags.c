/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 19:55:47 by qmerlot           #+#    #+#             */
/*   Updated: 2016/01/31 20:20:08 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	ft_is_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
		return (1);
	return (0);
}

const char	*ft_check_flags(const char *format, t_flags *flags)
{
	while (ft_is_flag(*format) == 1)
	{
		(*format == '#') ? flags->hash = 1 : 0;
		if (*format == '0' && flags->neg != 1)
			flags->zero = 1;
		if (*format == '-')
		{
			flags->neg = 1;
			flags->zero = 0;
		}
		if (*format == ' ' && flags->plus != 1)
			flags->space = 1;
		if (*format == '+')
		{
			flags->plus = 1;
			flags->space = 0;
		}
		format++;
	}
	return (format);
}
