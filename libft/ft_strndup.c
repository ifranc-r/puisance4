/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 19:12:34 by qmerlot           #+#    #+#             */
/*   Updated: 2016/02/01 19:12:38 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;

	str = ft_strnew(n);
	if (str == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	return (ft_strncpy(str, s1, n));
}
