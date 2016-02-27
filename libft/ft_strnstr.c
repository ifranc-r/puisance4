/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:30:40 by qmerlot           #+#    #+#             */
/*   Updated: 2015/11/29 20:11:34 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i] == s2[j])
		{
			if (i == n)
				return (NULL);
			i++;
			j++;
			if (s2[j] == '\0')
				return ((char*)&s1[i - j]);
		}
		if (i == n)
			return (NULL);
		i = i - j + 1;
	}
	return (NULL);
}
