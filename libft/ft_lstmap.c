/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 18:12:45 by qmerlot           #+#    #+#             */
/*   Updated: 2016/01/24 17:22:21 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*ret;

	newlist = NULL;
	ret = NULL;
	if (lst != NULL)
	{
		newlist = f(lst);
		ret = newlist;
		newlist->next = NULL;
		while (lst->next)
		{
			lst = lst->next;
			newlist->next = f(lst);
			newlist = newlist->next;
		}
	}
	return (ret);
}
