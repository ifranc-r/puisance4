/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:40:07 by qmerlot           #+#    #+#             */
/*   Updated: 2015/12/03 17:32:48 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		n;
	char	*str;

	n = 0;
	if ((str = ft_strnew(ft_strlen(s))))
	{
		while (s[n] != '\0')
		{
			str[n] = f(s[n]);
			n++;
		}
	}
	return (str);
}
