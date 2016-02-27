/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:04:29 by qmerlot           #+#    #+#             */
/*   Updated: 2015/11/26 18:52:40 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*t_dst;
	const char	*t_src;

	t_dst = dst;
	t_src = src;
	if (t_src <= t_dst)
	{
		t_dst += len - 1;
		t_src += len - 1;
		while (len--)
		{
			*t_dst-- = *t_src--;
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
