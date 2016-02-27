/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:27:30 by qmerlot           #+#    #+#             */
/*   Updated: 2015/11/28 15:57:49 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t_s;
	unsigned char	t_c;

	t_c = (unsigned char)c;
	t_s = (unsigned char *)s;
	while (n--)
	{
		if (*t_s++ == t_c)
			return (t_s - 1);
	}
	return (NULL);
}
