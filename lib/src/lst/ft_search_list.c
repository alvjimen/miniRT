/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:09:40 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/22 19:12:02 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lst.h"

t_list	*ft_search_list(t_list *lst, int (*f)(void *))
{
	t_list	*node;

	if (!lst)
		return (NULL);
	node = lst;
	while (lst)
	{
		if (!f(lst->content))
			break ;
		lst = lst->next;
	}
	return (lst);
}
