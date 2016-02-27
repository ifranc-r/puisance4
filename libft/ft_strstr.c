/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:42:46 by qmerlot           #+#    #+#             */
/*   Updated: 2015/11/29 17:27:36 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i] == s2[j])
		{
			i++;
			j++;
			if (s2[j] == '\0')
				return ((char*)&s1[i - j]);
		}
		i = i - j + 1;
	}
	return (NULL);
}
