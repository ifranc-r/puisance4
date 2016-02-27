/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:37:38 by qmerlot           #+#    #+#             */
/*   Updated: 2015/12/02 19:35:15 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_tabsize(char const *s, char c)
{
	int		size;

	size = 0;
	while (*s != '\0')
	{
		if (*s != c)
			size++;
		while (*s != c)
		{
			s++;
			if (*s == '\0')
				return (size);
		}
		s++;
	}
	return (size);
}

static int	ft_wordsize(char const *s, char c)
{
	int		wsize;

	wsize = 0;
	while (*s != c && *s != '\0')
	{
		wsize++;
		s++;
	}
	return (wsize);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		tabindex;
	int		words;

	tabindex = 0;
	words = ft_tabsize(s, c);
	if (!(tab = (char **)malloc(sizeof(*tab) * (words + 1))))
		return (NULL);
	while (words--)
	{
		while (*s != '\0' && *s == c)
			s++;
		if (!(tab[tabindex] = ft_strsub(s, 0, ft_wordsize(s, c))))
			return (NULL);
		s = s + ft_wordsize(s, c);
		tabindex++;
	}
	tab[tabindex] = NULL;
	return (tab);
}
