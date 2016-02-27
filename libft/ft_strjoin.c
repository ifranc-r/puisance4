/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:09:57 by qmerlot           #+#    #+#             */
/*   Updated: 2015/12/28 17:39:30 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_strnew(len);
	if (str != NULL)
	{
		if (s1 != NULL)
			str = ft_strcpy(str, s1);
		if (s2 != NULL)
			str = ft_strcat(str, s2);
	}
	return (str);
}
