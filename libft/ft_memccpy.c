/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:47:08 by qmerlot           #+#    #+#             */
/*   Updated: 2015/12/03 18:26:51 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*t_dst;
	const char	*t_src;

	t_dst = dst;
	t_src = src;
	if (n)
	{
		while (n--)
		{
			if ((*t_dst++ = *t_src++) == c)
				return (t_dst);
		}
	}
	return (NULL);
}
