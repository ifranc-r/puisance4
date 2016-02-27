/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:55:07 by qmerlot           #+#    #+#             */
/*   Updated: 2015/11/29 18:16:41 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		n;
	int		ret;

	n = 0;
	ret = -1;
	while (s[n] != '\0')
	{
		if (s[n] == c)
		{
			ret = n;
		}
		n++;
	}
	if (ret > -1)
		return ((char*)&s[ret]);
	if (!s[n] && s[n] == c)
		return ((char*)&s[n]);
	return (NULL);
}
