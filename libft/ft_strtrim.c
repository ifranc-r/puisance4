/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:16:14 by qmerlot           #+#    #+#             */
/*   Updated: 2015/12/03 17:46:40 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strtrimlen(char const *s)
{
	size_t	len;
	size_t	spend;

	len = 0;
	spend = 0;
	while (ft_isspace(*s) == 1 && *s != '\0')
		s++;
	while (*s != '\0')
	{
		if (ft_isspace(*s) == 1)
			spend++;
		else
			spend = 0;
		len++;
		s++;
	}
	return (len - spend);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;

	len = ft_strtrimlen(s);
	if ((str = ft_strnew(len)))
	{
		while (ft_isspace(*s) == 1 && *s != '\0')
			s++;
		str = ft_strncpy(str, s, len);
	}
	return (str);
}
