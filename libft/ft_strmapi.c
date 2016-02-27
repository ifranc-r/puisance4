/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:49:02 by qmerlot           #+#    #+#             */
/*   Updated: 2015/12/03 17:48:15 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		n;
	char	*str;

	n = 0;
	if ((str = ft_strnew(ft_strlen(s))))
	{
		while (s[n] != '\0')
		{
			str[n] = f(n, s[n]);
			n++;
		}
	}
	return (str);
}
