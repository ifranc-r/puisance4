/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 14:34:21 by qmerlot           #+#    #+#             */
/*   Updated: 2016/02/10 19:31:14 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <wchar.h>
#include <locale.h>

int		main(void)
{
	int					pf;
	int					wpf;
	int					fpf;
	int					i;
	long				u;
	wchar_t				c = L'Ӂ';

	setlocale(LC_ALL,"");
	i = 42;
	u = 4294967295;
//	pf = printf(
//	"{%05.Z}\n", 0);
	pf = printf(
	"%s\n", "lol");
	fpf = ft_printf(
	"%s\n", "lol");
//	printf("\npf -> %d\nfpf > %d\n", pf, fpf);
//	printf("\npf -> %d\n", fpf);
//	printf("itoa base 16 de 8572 : %X\n", 8572);
//	printf("itoa de 8572 : %s\n", ft_itoa_ll(8572));
//	while (1);
	return (0);
}
